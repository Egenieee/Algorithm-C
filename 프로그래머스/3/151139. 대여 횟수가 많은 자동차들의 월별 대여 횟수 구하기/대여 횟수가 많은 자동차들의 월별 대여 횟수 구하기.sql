# -- 2022년 8, 9, 10월 동안 5회 이상 대여한 차의 아이디
# with CAR_OVER_FIVE as (
#     select CAR_ID, count(*) as CNT
#     from CAR_RENTAL_COMPANY_RENTAL_HISTORY
#     where YEAR(START_DATE) = 2022 and MONTH(START_DATE) in (8, 9, 10)
#     group by CAR_ID
#     having CNT >= 5
# )

# -- CAR_OVER_FIVE 테이블에 있는 아이디를 가진 차 8월, 9월 10월 각 월별 개수 구하기

# select MONTH(START_DATE) as MONTH, CAR_ID, COUNT(HISTORY_ID) as RECORDS
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where CAR_ID in (select CAR_ID from CAR_OVER_FIVE)
# group by MONTH(START_DATE), CAR_ID
# order by MONTH asc, CAR_ID desc

select month(start_date)as MONTH,car_id as CAR_ID,count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(start_date) between 8 and 10  and
car_id in 
(
select car_id
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where month(start_date) between 8 and 10  
group by car_id
having count(*) >4
)
group by car_id,month
order by month asc ,car_id desc