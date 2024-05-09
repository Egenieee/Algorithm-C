-- 세단 종류 자동차 10월 대여 시작 자동차 ID 리스트 출력
select distinct R.CAR_ID 
from CAR_RENTAL_COMPANY_CAR as R inner join CAR_RENTAL_COMPANY_RENTAL_HISTORY as H on R.CAR_ID = H.CAR_ID
where MONTH(H.START_DATE) = '10' and R.CAR_TYPE = '세단'
order by R.CAR_ID desc;