# Write your MySQL query statement below
select
    event_day as day,
    emp_id,
    SUM(out_time) - SUM(in_time) as total_time
from
    Employees
group by
    day, emp_id