SELECT
    HG.TOTAL_SCORE AS SCORE,
    HG.EMP_NO,
    HE.EMP_NAME,
    HE.POSITION,
    HE.EMAIL
    
FROM
    (SELECT
         EMP_NO,
         SUM(SCORE) AS TOTAL_SCORE
     FROM
         HR_GRADE
     WHERE
         YEAR = 2022
     GROUP BY
         EMP_NO) AS HG
JOIN HR_EMPLOYEES HE ON HG.EMP_NO = HE.EMP_NO
WHERE HG.TOTAL_SCORE IN (
    SELECT MAX(TOTAL_SCORE)
    FROM (
        SELECT
            EMP_NO,
            SUM(SCORE) AS TOTAL_SCORE
        FROM
            HR_GRADE
        WHERE
            YEAR = 2022
        GROUP BY
            EMP_NO
    ) AS SUB
)
ORDER BY HG.EMP_NO ASC;
