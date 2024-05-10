-- 코드를 작성해주세요
with CHILD as 
(select count(*) as CHILD_COUNT, PARENT_ID
from ECOLI_DATA
where PARENT_ID is not null
group by PARENT_ID)

select E.ID, case when C.CHILD_COUNT is null then 0 else C.CHILD_COUNT end as CHILD_COUNT
from ECOLI_DATA as E left outer join CHILD as C on E.ID = C.PARENT_ID
