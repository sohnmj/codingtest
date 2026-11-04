/*
[로직] REST_INFO에서 FOOD_TYPE별 즐겨찾기 1위 식당 조회
[문법] RANK() OVER (PARTITION BY ... ORDER BY ... DESC), 윈도우 함수는 WHERE에 못 써서 서브쿼리로 감싸고 바깥에서 RK=1
[실수] ROW()는 없는 함수 → RANK()/ROW_NUMBER(). FROM 서브쿼리 별칭 누락 → Every derived table must have its own alias
[엣지] 동점이면 RANK는 공동 1위 모두 출력, ROW_NUMBER는 한 곳만. 최종 정렬은 FOOD_TYPE DESC
*/
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
FROM (
    SELECT REST_ID, REST_NAME, FOOD_TYPE, FAVORITES,
           RANK() OVER (PARTITION BY FOOD_TYPE ORDER BY FAVORITES DESC) AS RK
    FROM REST_INFO
) T
WHERE RK = 1
ORDER BY FOOD_TYPE DESC;