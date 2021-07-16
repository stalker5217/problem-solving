# Write your MySQL query statement below
SELECT
    Name AS "Customers"
FROM
    Customers
WHERE
    ID NOT IN (
        SELECT
            DISTINCT CustomerId 
        FROM
            Orders
    )