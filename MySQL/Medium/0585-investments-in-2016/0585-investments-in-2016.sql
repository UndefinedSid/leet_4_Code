# Write your MySQL query statement below

/* 1st approach

select round(sum(i.tiv_2016),2) as tiv_2016
    from insurance i
    where tiv_2015 in (select tiv_2015 from insurance 
                        group by tiv_2015
                        having count(*) > 1
                    )
        and (lat,lon) in(
            select lat,lon from insurance 
            group by lat,lon
            having count(*) =1
    );


*/

## CTE  approach (common table expression)

with RankedInsu as (
    select tiv_2016,
    count(*) over(partition by tiv_2015) as tiv_count,
    count(*) over (partition by lat,lon) as location
    from insurance
)
select round(sum(tiv_2016),2) as tiv_2016 
from RankedInsu
    where tiv_count > 1 and location =1;

