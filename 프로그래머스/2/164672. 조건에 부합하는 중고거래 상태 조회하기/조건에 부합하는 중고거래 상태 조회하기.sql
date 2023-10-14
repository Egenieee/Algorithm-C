-- 코드를 입력하세요
select b.board_id, b.writer_id, b.title, b.price, 
    if(b.status = 'sale', '판매중', if (b.status = 'reserved', '예약중', '거래완료')) as status
from used_goods_board b
where date_format(b.created_date, '%Y-%m-%d') = '2022-10-05'
order by b.board_id desc;