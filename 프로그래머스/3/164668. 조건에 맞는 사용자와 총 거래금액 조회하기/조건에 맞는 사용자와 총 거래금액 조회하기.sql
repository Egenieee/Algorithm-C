-- 완료된 중고 거래의 총금액이 70만원 이상인 사람의 회원 ID, 닉네임, 총거래금액 조회
select U.USER_ID, U.NICKNAME, SUM(B.PRICE) as TOTAL_SALES
from USED_GOODS_BOARD as B inner join USED_GOODS_USER as U on B.WRITER_ID = U.USER_ID
where B.STATUS = 'DONE'
group by B.WRITER_ID
having TOTAL_SALES >= 700000
order by TOTAL_SALES 