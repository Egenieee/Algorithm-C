-- 입양간 동물 중, 보호기간이 가장 길었던 동물 두 마리 
select OUTS.ANIMAL_ID, OUTS.NAME
from ANIMAL_INS as INS inner join ANIMAL_OUTS as OUTS on INS.ANIMAL_ID = OUTS.ANIMAL_ID
order by DATEDIFF(OUTS.DATETIME, INS.DATETIME) DESC
limit 2;

