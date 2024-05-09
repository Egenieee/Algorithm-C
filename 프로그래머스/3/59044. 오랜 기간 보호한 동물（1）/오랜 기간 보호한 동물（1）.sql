-- 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일
-- 보호 시작일 순으로 조회
SELECT INS.NAME, INS.DATETIME as DATETIME
FROM ANIMAL_INS as INS left outer join ANIMAL_OUTS as OUTS on INS.ANIMAL_ID = OUTS.ANIMAL_ID
WHERE OUTS.DATETIME is null
ORDER BY INS.DATETIME
LIMIT 3;