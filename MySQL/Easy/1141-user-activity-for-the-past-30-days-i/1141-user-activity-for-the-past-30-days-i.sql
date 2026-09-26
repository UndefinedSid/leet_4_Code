# Write your MySQL query statement below
/*. using DATEDIFF Approach

select activity_date as day,
    count(distinct user_id ) as active_users from activity
    where DATEDIFF('2019-07-27',activity_date) >=0
        and DATEDIFF('2019-07-27', activity_date) < 30
group by activity_date;

*/

## using CTE approach

with activityCTE as(
    select distinct user_id,activity_date
    from activity
    where activity_date between '2019-06-28' and '2019-07-27'
)
select activity_date as day,
    count(distinct user_id ) as active_users
from activityCTE
group by activity_date;