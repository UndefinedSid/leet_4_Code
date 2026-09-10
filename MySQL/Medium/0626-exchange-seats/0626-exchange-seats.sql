# Write your MySQL query statement below
/*

select 
case
    when id % 2 = 0 then id - 1
    when id= (select max(id) from seat ) then id
    else id + 1
end as id, student
from seat
order by id asc;

*/

# window function and coalesce approach
## COALESCE is an SQL function that returns the first non-null value in a list of arguments. If the first argument is NULL, it evaluates the second; if that is also NULL, it continues down the list until it finds a value that is not NULL.

select id,
    case 
    when id % 2 = 0 then (lag(student) over (order by id))
    else coalesce(lead(student) over (order by id), student)
    end as student
from seat;
