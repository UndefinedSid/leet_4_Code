# Write your MySQL query statement below

with qualityCte as (
    select query_name,
    rating * 1.0 /position as ratio,
    case when rating < 3 then 1 else 0 end as is_poor
    from queries
    -- where query_name is not null
)
select query_name, round(avg(ratio),2) as quality,
    round(avg(is_poor) * 100 ,2) as poor_query_percentage
 from qualityCte
 group by query_name;
