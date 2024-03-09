package main

import (
	"context"
	"time"

	"github.com/sirupsen/logrus"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

type Table struct {
	ID       primitive.ObjectID `bson:"_id,omitempty"`
	Lables   string             `bson:"lables,omitempty"`
	CarId    string             `bson:"car_id,omitempty"`
	Message  string             `bson:"message,omitempty"`
	CreatAt  time.Time          `bson:"creat_at,omitempty"`
	UpdateAt time.Time          `bson:"update_at,omitempty"`
}

type UpdatePayload struct {
	ID      *string `bson:"_id,omitempty"`
	Lables  string  `bson:"lables,omitempty"`
	CarId   string  `bson:"car_id,omitempty"`
	Message string  `bson:"message,omitempty"`
}

type UpdatePayloadWrapper struct {
	UpdatePayload *UpdatePayload `bson:"inline"`
	UpdateAt      time.Time      `bson:"update_at,omitempty"`
}

func init() {
	logrus.SetFormatter(&logrus.TextFormatter{
		FullTimestamp: true,
	})
}

/**

docker run --name mongo -p 27017:27017 -d mongodb/mongodb-community-server:latest

**/

func main() {
	clientOptions := options.Client().ApplyURI("mongodb://localhost:27017")
	client, err := mongo.Connect(context.TODO(), clientOptions)
	if err != nil {
		logrus.Fatal(err)
	}

	err = client.Ping(context.TODO(), nil)
	if err != nil {
		logrus.Fatal(err)
	}

	logrus.Info("Connected to MongoDB!")
	collection := client.Database("test").Collection("trainers")
	deleteResult, err := collection.DeleteMany(context.TODO(), bson.D{{}})
	if err != nil {
		logrus.Fatal(err)
	}

	logrus.Printf("Deleted %v documents in the trainers collection\n", deleteResult.DeletedCount)
	// Some dummy data to add to the Database
	ash := Table{CarId: "card1", Lables: "1,2,3", Message: "msg1"}
	insertResult, err := collection.InsertOne(context.TODO(), ash)
	if err != nil {
		logrus.Fatal(err)
	}
	logrus.Info("Inserted a single document: ", insertResult.InsertedID)

	var result UpdatePayload
	err = collection.FindOne(context.TODO(), bson.M{"_id": insertResult.InsertedID}).Decode(&result)
	if err != nil {
		logrus.Fatal(err)
	}

	// Update a document
	filter := bson.M{"_id": insertResult.InsertedID}
	result.CarId = "updated"
	result.ID = nil
	var wrapper UpdatePayloadWrapper = UpdatePayloadWrapper{UpdatePayload: &result}
	wrapper.UpdateAt = time.Now()

	// update := bson.D{
	// 	{"$set", result},
	// }

	// update := bson.M{
	// 	"$set": result,
	// }

	update := bson.M{
		"$set": wrapper,
	}

	updateResult, err := collection.UpdateOne(context.TODO(), filter, update)
	if err != nil {
		logrus.Fatal(err)
	}
	logrus.Printf("Matched %v documents and updated %v documents.\n", updateResult.MatchedCount, updateResult.ModifiedCount)

}
