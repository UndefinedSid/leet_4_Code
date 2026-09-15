# Write your MySQL query statement below

/*
## self join approach -> O(N ^ 2)

select a1.machine_id,
    round(avg(a2.timestamp - a1.timestamp),3) as processing_time
from activity a1
    join activity a2
    on a1.machine_id=a2.machine_id
    and a1.process_id=a2.process_id
where a1.activity_type='start' and a2.activity_type='end'
group by a1.machine_id;

*/

## conditional Aggregation Approach -> O(N)

select machine_id,round(sum(case when activity_type='end' then timestamp 
        else - timestamp end) / count(distinct process_id), 3) 
        as processing_time
    from activity
group by machine_id;