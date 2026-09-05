# Write your MySQL query statement below
(
    select u.name as results from users u 
    join movierating mr on u.user_id=mr.user_id
    group by u.user_id,u.name
    order by count(mr.movie_id) desc,u.name asc
    limit 1
) 
union all
(
    select m.title as results from movies m
    join movierating mr on m.movie_id=mr.movie_id
    where mr.created_at >= '2020-02-01' and mr.created_at <= '2020-02-29'
    group by  m.movie_id,m.title
    order by avg(mr.rating) desc,m.title asc
    limit 1
);