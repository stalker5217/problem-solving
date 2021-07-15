# Write your MySQL query statement below
SELECT
    Name As Employee
FROM
    Employee E
WHERE
    ManagerId IS NOT NULL
    AND Salary > (SELECT Salary From Employee I WHERE I.id = E.ManagerId)