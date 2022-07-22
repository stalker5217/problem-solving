select
    w1.id
from
    Weather w1, Weather w2
where
    w2.recordDate = date_sub(w1.recordDate, interval 1 day)
    and
    w1.temperature > w2.temperature;