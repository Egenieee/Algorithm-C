-- 부서별 평균 연봉 조회
-- 부서별로 부서ID, 영문 부서명, 평균 연봉 조회
-- 평균 연봉은 소수점 첫째 자리에서 반올림하고 컬럼명은 AVG_SAL
-- 평균 연봉 기준으로 내림차순

select D.DEPT_ID, D.DEPT_NAME_EN, ROUND(AVG(E.SAL), 0) as AVG_SAL
from HR_DEPARTMENT as D inner join HR_EMPLOYEES as E on D.DEPT_ID = E.DEPT_ID
group by D.DEPT_ID
order by AVG_SAL desc