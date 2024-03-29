SELECT
    CASE
        WHEN (D.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python') > 0)
             AND (D.SKILL_CODE & (
                 SELECT SUM(CODE)
                 FROM SKILLCODES
                 WHERE CATEGORY = 'Front End'
             ) > 0) THEN 'A'
        WHEN D.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#') > 0 THEN 'B'
        WHEN D.SKILL_CODE & (
                 SELECT SUM(CODE)
                 FROM SKILLCODES
                 WHERE CATEGORY = 'Front End'
             ) > 0 THEN 'C'
        ELSE NULL
    END AS GRADE,
    D.ID,
    D.EMAIL
FROM
    DEVELOPERS D
WHERE
    CASE
        WHEN (D.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'Python') > 0)
             AND (D.SKILL_CODE & (
                 SELECT SUM(CODE)
                 FROM SKILLCODES
                 WHERE CATEGORY = 'Front End'
             ) > 0) THEN 'A'
        WHEN D.SKILL_CODE & (SELECT CODE FROM SKILLCODES WHERE NAME = 'C#') > 0 THEN 'B'
        WHEN D.SKILL_CODE & (
                 SELECT SUM(CODE)
                 FROM SKILLCODES
                 WHERE CATEGORY = 'Front End'
             ) > 0 THEN 'C'
    END IS NOT NULL
ORDER BY
    GRADE, D.ID;
