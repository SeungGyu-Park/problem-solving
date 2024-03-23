SELECT
    fi.ID ID, fni.FISH_NAME, fi.LENGTH
FROM
    FISH_INFO fi
JOIN
    FISH_NAME_INFO fni
ON
    fi.FISH_TYPE = fni.FISH_TYPE
WHERE
    FI.LENGTH = (
        SELECT
            MAX(LENGTH)
        FROM
            FISH_INFO
        WHERE
            FISH_TYPE = FI.FISH_TYPE
    )
ORDER BY
    fi.ID
    