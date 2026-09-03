# Write your MySQL query statement below
/*1st approach 
select max(salary) as SecondHighestSalary from Employee
where salary < (
    select max(salary) from Employee
);

*/

## 2nd approach

select ifnull(
(select distinct salary from employee 
order by salary desc limit 1 offset 1
),null) as SecondHighestSalary;



