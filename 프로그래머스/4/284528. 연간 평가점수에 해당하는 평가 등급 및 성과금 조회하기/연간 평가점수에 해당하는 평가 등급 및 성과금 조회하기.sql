SELECT
    he.EMP_NO,
    he.EMP_NAME,
    CASE
        WHEN AVG(hg.SCORE) >= 96 THEN 'S'
        WHEN AVG(hg.SCORE) >= 90 THEN 'A'
        WHEN AVG(hg.SCORE) >= 80 THEN 'B'
        ELSE 'C'
    END GRADE,
    CASE
        WHEN AVG(hg.SCORE) >= 96 THEN he.SAL*0.20
        WHEN AVG(hg.SCORE) >= 90 THEN he.SAL*0.15
        WHEN AVG(hg.SCORE) >= 80 THEN he.SAL*0.10
        ELSE 0
    END BONUS

FROM
    HR_EMPLOYEES he
JOIN
    HR_GRADE hg
ON
    he.EMP_NO = hg.EMP_NO
GROUP BY
    he.EMP_NO
ORDER BY
    he.EMP_NO