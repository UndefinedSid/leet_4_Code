# Write your MySQL query statement below
select e.employee_id,e.name,count(em.employee_id) as reports_count,
    round(avg(em.age)) as average_age
    from employees e
    join employees em
    on e.employee_id=em.reports_to
    group by e.employee_id,e.name
    order by e.employee_id asc;
