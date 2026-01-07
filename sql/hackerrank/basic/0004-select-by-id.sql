-- Hackerrank SQL: Basic Select
-- Problem: Select By ID
-- Source: https://www.hackerrank.com/challenges/select-by-id/problem
--
-- Query all columns for a city in CITY with the ID 1661.
--
-- Solution:
/*
    Enter your query here and follow these instructions:
    1. Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
    2. The AS keyword causes errors, so follow this convention: "Select t.Field From table1 t" instead of "select t.Field From table1 AS t"
    3. Type your code immediately after comment. Don't leave any blank line.
*/
SELECT * FROM CITY WHERE ID = 1661;

-- Complexity Analysis:
-- Time Complexity: O(N), where N is the number of rows in CITY (assuming no index)
-- Space Complexity: O(1)
-- This is the optimal solution for this problem.
