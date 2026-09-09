# Write your MySQL query statement below
with filtered as (
    select id,visit_date,people,
    id - row_number() over (order by id) as idGroup
    from stadium 
    where people >= 100
),
validGroup as (
    select id,visit_date,people,
    count(*) over (partition by idGroup) as groupCount
    from filtered
)

select id,visit_date,people from validGroup
where groupCount >=3
order by visit_date asc;