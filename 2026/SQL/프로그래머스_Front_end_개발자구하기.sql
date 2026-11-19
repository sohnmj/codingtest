/*
[로직] DEVELOPERS×SKILLCODES에서 가진 스킬(비트 AND)이 Front End인 개발자만 추림
[문법] SKILL_CODE & CODE 결과는 0 또는 CODE 값(4,256..) → =1 말고 >0으로 판정. MySQL은 &가 >보다 먼저(C++은 반대라 괄호 필수)
[엣지] 프론트 스킬 여러 개 가진 개발자는 행 중복 → DISTINCT. CATEGORY='Front End' 띄어쓰기 정확히
*/
SELECT DISTINCT D.ID, D.EMAIL, D.FIRST_NAME,D.LAST_NAME
FROM  DEVELOPERS D,SKILLCODES S
WHERE D.SKILL_CODE & S.CODE>0 AND S.CATEGORY='Front End'
ORDER BY D.ID