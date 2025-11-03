# Write your MySQL query statement below
select v.customer_id, Count(customer_id) as count_no_trans
from Visits as v
LEFT JOIN 
Transactions as t
        ON v.visit_id = t.visit_id
            where t.transaction_id is null
        Group BY v.customer_id