# Write your MySQL query statement below
## 1st approach

-- select employee_id from employees 
-- where salary < 30000 and  manager_id not in 
-- (select employee_id from employees)
-- order by employee_id;

## 2nd Approach

select e1.employee_id from employees e1 
left join employees e2 
on e1.manager_id=e2.employee_id
where e1.salary < 30000 and 
e1.manager_id is not null
and e2.employee_id is null
order by e1.employee_id;