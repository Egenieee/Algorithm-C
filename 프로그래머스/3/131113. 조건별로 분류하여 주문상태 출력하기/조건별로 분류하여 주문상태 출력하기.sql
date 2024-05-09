-- 5월 1일 기준으로 이전이면 출고완료, 이후는 출고대기, 미정이면 출고미정으로 출력
-- ID기준 오름차순 정렬

select ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, '%Y-%m-%d') as OUT_DATE, 
case 
    when OUT_DATE <= '2022-05-01' then '출고완료' 
    when OUT_DATE >= '2022-05-02' then '출고대기'
    when OUT_DATE is null then '출고미정'
end as '출고여부'
from FOOD_ORDER
order by ORDER_ID