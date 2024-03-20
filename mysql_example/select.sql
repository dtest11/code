create table world (
    name varchar(100) primary key,
    continent varchar(100) not null,
    area int not null,
    population int not null,
    gdp bigint not null
) -- A country is big if:
-- it has an area of at least three million (i.e., 3000000 km2), or
-- it has a population of at least twenty-five million (i.e., 25000000).
-- Write a solution to find the name, population, and area of the big countries.
-- Return the result table in any order.
-- The result format is in the following example.
SELECT
    name,
    population,
    area
FROM
    World
WHERE
    area >= 3000000
    OR population >= 25000000;

-- 43 最少看过自己文章一次的
create table views (
    article_id int,
    author_id int,
    viewer_id int,
    view_date date
);

select
    distinct author_id as id
from
    Views
where
    author_id = viewer_id
order by
    id;

-- 1684
create table tweets (tweet_id int primary key, content varchar(100));

select
    *
from
    tweets
where
    length(content) < 15;

---
create table Employees (
    id int primary key,
    name varchar(100) not null
);

create table EmployeeUNI(
    id int,
    unique_id int,
    primary key(id, unique_id)
);

select
    EmployeeUNI.unique_id,
    Employees.name
from
    Employees
    left join EmployeeUNI on Employees.id = EmployeeUNI.id;

----
create table product (
    product_id int primary key,
    product_name varchar(100)
);

create table sales (
    sale_id int,
    product_id int,
    year int,
    quantity int,
    price int,
    primary key(sale_id, year),
    foreign key(product_id) REFERENCES product(product_id)
);

select
    p.product_name,
    s.year,
    s.price
from
    sales s
    inner join product p on s.product_id = p.product_id;

-----
create table visits (visit_id int unique, customer_id int);

create table transactions (
    transaction_id int unique,
    visit_id int,
    amount int
);

-------- 没有发生交易的人
-- select
--     *
-- from
--     visits as v
--     left join transactions as t;
select
    v.customer_id,
    count(v.customer_id)
from
    visits as v
where
    v.visit_id not in (
        select
            visit_id
        from
            transactions
        where
            amount > 0
    )
group by
    v.customer_id;

---- left join的方法
SELECT
    v.customer_id,
    COUNT(v.visit_id) as count_no_trans
FROM
    Visits AS v
    LEFT JOIN Transactions AS t ON v.visit_id = t.visit_id
WHERE
    t.transaction_id IS NULL
GROUP BY
    v.customer_id;