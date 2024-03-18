package main

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"time"

	"github.com/hibiken/asynq"
	"github.com/robfig/cron/v3"
)

/**
docker run -itd --name myRedis -p 6379:6379 redis
**/

const TypeEmailDelivery = "delivery"

func processEmailDelivery(context.Context, *asynq.Task) error {
	log.Println("process task")
	time.Sleep(3 * time.Second)
	return nil
}

// distributed cron task support Scheduling
var standardParser = cron.NewParser(
	cron.Minute | cron.Hour | cron.Dom | cron.Month | cron.Dow | cron.Descriptor,
)

type CronTask struct {
	Id       int64
	TypeName string
	CronSpec string
}

func (c *CronTask) GetNext() time.Time {
	withLoc := fmt.Sprintf("CRON_TZ=%s %s", time.Local, c.CronSpec)
	s, err := standardParser.Parse(withLoc)
	if err != nil {
		panic(err)
	}
	return s.Next(time.Now())
}

type HandleFunc func(id int64) error
type CronScheduler struct {
	client    *asynq.Client
	server    *asynq.Server
	inspector *asynq.Inspector
	handlers  map[string]HandleFunc
}

const cronType = "cron"

func NewCronScheduler(opt asynq.RedisClientOpt) *CronScheduler {
	server := asynq.NewServer(opt, asynq.Config{Concurrency: 5})
	client := asynq.NewClient(opt)
	return &CronScheduler{server: server, client: client}
}

func (c *CronScheduler) Push(t *CronTask) error {
	bt, err := json.Marshal(t)
	if err != nil {
		return err
	}
	execAt := t.GetNext()
	taskId := fmt.Sprintf("%s-%d", t.TypeName, t.Id)
	task := asynq.NewTask(cronType, bt, asynq.ProcessAt(execAt), asynq.TaskID(taskId))
	_, err = c.client.Enqueue(task)
	return err
}

func (c *CronScheduler) Remove(typeName string, id int64) error {
	taskId := fmt.Sprintf("%s-%d", typeName, id)
	return c.inspector.DeleteTask("default", taskId)
}

func (c *CronScheduler) RegisterHandler(typeName string, h HandleFunc) {
	c.handlers[typeName] = h
}

func (c *CronScheduler) HandleCronTask(_ context.Context, task *asynq.Task) error {
	var t CronTask
	if err := json.Unmarshal(task.Payload(), &t); err != nil {
		return err
	}
	h, ok := c.handlers[t.TypeName]
	if !ok {
		return fmt.Errorf("not found handler for %s", t.TypeName)
	}
	if err := h(t.Id); err != nil {
		return err
	}

	return c.Push(&t)
}

func main() {
	redisClientOpt := asynq.RedisClientOpt{
		Addr: "localhost:6379",
		DB:   0,
	}
	server := asynq.NewServer(redisClientOpt,
		asynq.Config{Concurrency: 5},
	)
	c := NewCronScheduler(redisClientOpt)

	mux := asynq.NewServeMux()
	mux.HandleFunc(TypeEmailDelivery, processEmailDelivery)
	mux.HandleFunc(cronType, c.HandleCronTask)

	if err := server.Run(mux); err != nil {
		log.Fatalf("could not run server: %v", err)
	}
}
