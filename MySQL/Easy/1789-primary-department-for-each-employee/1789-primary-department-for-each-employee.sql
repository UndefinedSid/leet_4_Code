# Write your MySQL query statement below
# Union Approach
/*
select employee_id,department_id 
from employee
group by employee_id
having count(employee_id) = 1

union

select employee_id,department_id
from employee 
where primary_flag='Y';

*/

# Using Conditional Filtering (OR logic)

select employee_id,department_id
from employee
where primary_flag='Y' OR employee_id in
    (   
    select employee_id from employee
    group by employee_id
    having count(department_id)=1
);  

