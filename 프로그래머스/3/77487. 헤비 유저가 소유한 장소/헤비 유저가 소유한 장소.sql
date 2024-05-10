-- 2개 공간 이상 등록한 유저를 헤비 유저라고 하는데, 헤비 유저가 등록한 공간의 정보를 아이디 순으로 조회
select ID, NAME, HOST_ID
from PLACES
where HOST_ID in (select HOST_ID from PLACES group by HOST_ID having COUNT(*) >= 2)
order by ID
