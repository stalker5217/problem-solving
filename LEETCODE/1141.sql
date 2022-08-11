# Write your MySQL query statement below
select
    activity_date as day,
    count(distinct user_id) as active_users
from
    Activity
where
    activity_date <= STR_TO_DATE('2019-07-27', '%Y-%m-%d')
    AND activity_date > DATE_SUB(STR_TO_DATE('2019-07-27', '%Y-%m-%d'), INTERVAL 30 DAY)
group by
    activity_date