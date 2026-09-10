# Write your MySQL query statement below
with sumTotal as(
    select
    person_name,turn,
    sum(weight)  over (order by turn asc) as Total_Weight
    from queue
    )
    select person_name from sumTotal
    where Total_Weight <= 1000
    order by turn desc
    limit  1;
