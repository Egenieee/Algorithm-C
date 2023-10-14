-- 코드를 입력하세요
select count(*) as users
from user_info
where age >= 20 and age <= 29 and joined >= '2021-01-01' and joined <= '2021-12-31';