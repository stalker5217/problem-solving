# Write your MySQL query statement below
WITH Result AS (
    SELECT
        D.Name AS Department,
        E.Name AS Employee,
        Salary AS Salary,
        DENSE_RANK() OVER(PARTITION BY DepartmentId ORDER BY Salary DESC) AS _RANK
    FROM
        Employee E
    JOIN
        Department D
    ON
        D.Id = E.DepartmentId
)

SELECT
    Department,
    Employee,
    Salary
FROM
    Result
WHERE
    _RANK = 1