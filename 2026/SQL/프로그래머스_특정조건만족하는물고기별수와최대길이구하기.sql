--AVG(IFNULL(LENGTH, 10))이런식으로 함수안에 함수를 넣는 방식으로 치환이 가능핟.                                                       
SELECT 
    COUNT(*) AS FISH_COUNT, 
    MAX(LENGTH) AS MAX_LENGTH, 
    FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(IFNULL(LENGTH, 10)) >= 33
ORDER BY FISH_TYPE ASC;