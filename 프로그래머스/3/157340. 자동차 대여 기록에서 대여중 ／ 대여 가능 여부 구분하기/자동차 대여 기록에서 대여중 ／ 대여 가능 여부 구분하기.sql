-- 코드를 입력하세요
# select CAR_ID, 
# case 
#     when SUM(case when 1 = 1 then 1 else 0) >= 1 then '대여중'
#     else '대여 가능'
# end as AVAILABILITY 
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# group by CAR_ID
# order by CAR_ID desc

SELECT CAR_ID, 
CASE 
    WHEN SUM(CASE WHEN START_DATE <= '2022-10-16' and END_DATE >= '2022-10-16' THEN 1 ELSE 0 END) >= 1 THEN '대여중'
    ELSE '대여 가능'
END AS AVAILABILITY 
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
GROUP BY CAR_ID
ORDER BY CAR_ID DESC

# case when START_DATE <= '2022-10-16' and END_DATE >= '2022-10-16' 