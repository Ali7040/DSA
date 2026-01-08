/*
LeetCode 10. Regular Expression Matching
Hard

Problem Statement:
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Examples:
Input: s = "aa", p = "a"
Output: false
Input: s = "aa", p = "a*"
Output: true
Input: s = "ab", p = ".*"
Output: true

Constraints:
- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

Approach:
Dynamic Programming (DP) is used to handle the matching, including wildcards '.' and '*'.

Complexity Analysis:
- Time: O(n*m), where n = s.length, m = p.length
- Space: O(n*m)

*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // zero occurrence
                    dp[i][j] = dp[i][j - 2];
                    // one or more occurrence
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

// Test cases and further explanation can be added below as needed.
