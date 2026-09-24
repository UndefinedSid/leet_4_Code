# Write your MySQL query statement below

/* without CTE Approach

select round(avg(order_date=customer_pref_delivery_date) * 100 ,2) as immediate_percentage
from delivery
where (customer_id,order_date) in(
    select customer_id,min(order_date)
    from delivery
    group by customer_id
);

*/
## with CTE 

with rankedCTE as(
    select customer_id,order_date,customer_pref_delivery_date,
    rank() over(partition by customer_id order by order_date) as rk
    from delivery
)
select round(avg(if(order_date=customer_pref_delivery_date,1,0)) * 100,2) as immediate_percentage
from rankedCTE
where rk=1;

