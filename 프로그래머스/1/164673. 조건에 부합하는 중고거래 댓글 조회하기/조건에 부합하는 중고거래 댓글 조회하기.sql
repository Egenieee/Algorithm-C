-- 코드를 입력하세요
# SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, DATE_FORMAT(R.CREATED_DATE, '%y-%m-%d') as CREATED_DATE
# FROM USED_GOODS_BOARD B JOIN USED_GOODS_REPLY R ON B.BOARD_ID = R.BOARD_ID
# WHERE  B.CREATED_DATE >= '2022-10-01' AND B.CREATED_DATE <= '2022-10-31'
# ORDER BY R.CREATED_DATE ASC, B.TITLE DESC;

select b.title, b.board_id, r.reply_id, r.writer_id, r.contents, date_format(r.created_date, '%Y-%m-%d') as created_date
from used_goods_board b join used_goods_reply r on b.board_id = r.board_id
where b.created_date >= '2022-10-01' and b.created_date <= '2022-10-31'
order by r.created_date asc, b.title asc;

# select r.contents, r.created_date, r.board_id
# from used_goods_reply r
# where r.created_date >= '2022-10-01' and r.created_date <= '2022-10-31';