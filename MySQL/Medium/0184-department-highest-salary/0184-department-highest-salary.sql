# Write your MySQL query statement below

/* 
## normal approach

SELECT d.name AS Department,e.name AS Employee,e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId=d.id
WHERE (e.departmentId,e.salary) IN (
    SELECT departmentId,MAX(salary) FROM Employee
    GROUP BY departmentId
);

 */

 ## CTE approach

 with cteResult as(
    select d.name as department,
            e.name as employee,
            e.salary as salary,
        dense_rank() over (partition by e.departmentId 
                    order by e.salary desc) as rnk
        from employee e
        join department d on e.departmentId=d.id
 )
 select department,employee,salary from cteResult where rnk=1;
