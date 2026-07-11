#MAX는 단순히 가장 높은 숫자만 반환하고 그에 해당하는 레코드를 조회해주지는 않는다.
select HR_SUM.SCORE_SUM SCORE, E.EMP_NO EMP_NO,E.EMP_NAME EMP_NAME, E.POSITION POSITION,E.EMAIL EMAIL
from HR_EMPLOYEES E 
join
(select sum(score) as SCORE_SUM, E2.EMP_NO EMP_NO
from HR_EMPLOYEES E2
join HR_GRADE G
on E2.EMP_NO=G.EMP_NO
group by E2.EMP_NO) HR_SUM
on HR_SUM.EMP_NO = E.EMP_NO
order by SCORE DESC
limit 1;