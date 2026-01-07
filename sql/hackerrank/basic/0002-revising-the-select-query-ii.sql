-- Hackerrank SQL: Basic Select
-- Problem: Revising the Select Query II
-- Source: https://www.hackerrank.com/challenges/revising-the-select-query-2/problem
--
-- Query the NAME field for all American cities in the CITY table with populations larger than 120000. The CountryCode for America is USA.
--
-- Solution:
/*
    Enter your query here and follow these instructions:
    1. Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
    2. The AS keyword causes errors, so follow this convention: "Select t.Field From table1 t" instead of "select t.Field From table1 AS t"
    3. Type your code immediately after comment. Don't leave any blank line.
*/
SELECT NAME FROM CITY WHERE CountryCode = 'USA' AND Population > 120000;

-- Complexity Analysis:
-- Time Complexity: O(N), where N is the number of rows in CITY
-- Space Complexity: O(1)
-- This is the optimal solution for this problem.
