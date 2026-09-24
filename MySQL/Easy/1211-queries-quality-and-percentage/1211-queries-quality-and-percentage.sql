# Write your MySQL query statement below
/*  CTE Approach
with qualityCte as (
    select query_name,
    rating * 1.0 /position as ratio,
    case when rating < 3 then 1 else 0 end as is_poor
    from queries
    where query_name is not null
)
select query_name, round(avg(ratio),2) as quality,
    round(avg(is_poor) * 100 ,2) as poor_query_percentage
 from qualityCte
 group by query_name;


*/
 ## without CTE

select query_name,
    round(avg(rating / position),2) as quality,
    round(avg(
        case when rating < 3 then 1 else 0 end 
    ) * 100 ,2) as poor_query_percentage
from queries 
where query_name is not null
group by query_name;