# Write your MySQL query statement below
select
    u.name as name,
    IFNULL(sum(r.distance), 0) as travelled_distance
from
    Users u
left outer join
    Rides r
on
    r.user_id = u.id
group by
    u.id
order by
    travelled_distance desc, name asc
