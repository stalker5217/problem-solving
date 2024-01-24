# Write your MySQL query statement below
select 
    x, y, z, 
    CASE WHEN x + y > z and y + z > x and x + z > y then 'Yes' 
    else 'No' end triangle
from
    Triangle  