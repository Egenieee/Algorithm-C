-- 코드를 입력하세요
select OUTS.ANIMAL_ID, OUTS.NAME
from ANIMAL_INS as INS right outer join ANIMAL_OUTS as OUTS on INS.ANIMAL_ID = OUTS.ANIMAL_ID
where INS.DATETIME is null
order by OUTS.ANIMAL_ID