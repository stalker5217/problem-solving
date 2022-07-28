select
    name
from
    SalesPerson
where
    sales_id not in (select O.sales_id from Orders O join Company C on O.com_id = C.com_id AND C.name = 'RED')