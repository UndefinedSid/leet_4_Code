# Write your MySQL query statement below
select customer_id from Customer
    group by customer_id
    having count(Distinct product_key) = (select count(*) from product);