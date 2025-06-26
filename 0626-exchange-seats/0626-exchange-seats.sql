# Write your MySQL query statement below
select s.id ,
case
    when mod(s.id,2)=1 and s.id < (select max(id) from Seat)
        then (select student from Seat where id = s.id + 1)
    when mod(s.id , 2) = 0 
        then (select student from Seat where id = s.id - 1)
    else s.student
end as student
from Seat s
order by s.id;