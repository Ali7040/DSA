/*
 * Problem: [Problem Name]
 * Platform: [LeetCode/HackerRank/etc.]
 * Problem Number: [Number]
 * Difficulty: [Easy/Medium/Hard]
 * Link: [Problem URL]
 * 
 * Problem Statement:
 * [Brief description of the problem]
 * 
 * Approach 1: [Approach Name - e.g., Using JOIN]
 * Performance: [Query execution time, if available]
 * 
 * Approach 2: [Approach Name - e.g., Using Subquery]
 * Performance: [Query execution time, if available]
 * 
 * Optimal Solution: [Which approach and why]
 * 
 * Notes:
 * - Index considerations
 * - Query optimization tips
 * - Alternative methods
 */

-- Approach 1: [Description]
-- Example: Using INNER JOIN
SELECT 
    -- columns
FROM 
    table1 t1
INNER JOIN 
    table2 t2 ON t1.id = t2.id
WHERE 
    -- conditions
ORDER BY 
    -- columns
;

-- Approach 2: [Description]
-- Example: Using Subquery
SELECT 
    -- columns
FROM 
    table1
WHERE 
    id IN (
        SELECT id FROM table2 WHERE -- conditions
    )
;

-- Approach 3: [Description - if applicable]
-- Example: Using CTE (Common Table Expression)
WITH cte AS (
    SELECT 
        -- columns
    FROM 
        table1
    WHERE 
        -- conditions
)
SELECT 
    -- columns
FROM 
    cte
WHERE 
    -- conditions
;

