        select a.QUATER, count(a.ID) ECOLI_COUNT
        from (select case
                    when MONTH(DIFFERENTIATION_DATE)<=3 then '1Q'
                    when MONTH(DIFFERENTIATION_DATE)<=6 then '2Q'
                    when MONTH(DIFFERENTIATION_DATE)<=9 then '3Q'
                    else '4Q'
                end QUATER, ID
               from ECOLI_DATA) a 
        group by (a.QUATER)
        order by a.QUATER

group by에서 alias 사용가능 내부 sql구문 사용할 필요없음

SELECT CASE
           WHEN MONTH(DIFFERENTIATION_DATE) <= 3 THEN '1Q'
           WHEN MONTH(DIFFERENTIATION_DATE) <= 6 THEN '2Q'
           WHEN MONTH(DIFFERENTIATION_DATE) <= 9 THEN '3Q'
           ELSE '4Q'
       END AS QUARTER,
       COUNT(*) AS ECOLI_COUNT
FROM ECOLI_DATA
GROUP BY QUARTER
ORDER BY QUARTER;