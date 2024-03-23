SELECT
    D.ID,
    D.EMAIL,
    D.FIRST_NAME,
    D.LAST_NAME
FROM
    DEVELOPERS D
WHERE
    (D.SKILL_CODE & 256) > 0 OR (D.SKILL_CODE & 1024) > 0
ORDER BY
    D.ID;
