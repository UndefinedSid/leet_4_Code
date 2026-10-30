# Write your MySQL query statement below
with dailyCte as(
    select visited_on,
    sum(amount) as amount
    from customer
    group by visited_on
)
select t1.visited_on,
    sum(t2.amount) as amount,
    round(avg(t2.amount),2) as average_amount
from dailyCte t1 
join dailyCte t2
    on t2.visited_on 
    between DATE_SUB(t1.visited_on,interval 6 day) and t1.visited_on
group by t1.visited_on
having count(t2.visited_on) = 7
order by t1.visited_on;