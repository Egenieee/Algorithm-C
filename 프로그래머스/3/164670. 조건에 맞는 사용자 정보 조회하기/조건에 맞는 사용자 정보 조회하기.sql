-- 코드를 입력하세요
select U.USER_ID, U.NICKNAME,
    CONCAT(U.CITY, ' ', U.STREET_ADDRESS1, ' ', U.STREET_ADDRESS2) as '전체주소',
    CONCAT(SUBSTR(U.TLNO, 1, 3), '-', SUBSTR(U.TLNO, 4, 4), '-', SUBSTR(U.TLNO, 8, 4)) as '전화번호'
from USED_GOODS_BOARD as B inner join USED_GOODS_USER as U on B.WRITER_ID = U.USER_ID
group by U.USER_ID
having COUNT(*) >= 3
order by U.USER_ID DESC