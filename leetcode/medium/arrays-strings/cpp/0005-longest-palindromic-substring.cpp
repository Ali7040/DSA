/*
 * Problem: Longest Palindromic Substring
 * Platform: LeetCode
 * Problem Number: 5
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-palindromic-substring/
 *
 * Problem Statement:
 * Given a string s, return the longest palindromic substring in s.
 *
 * Examples:
 * Input: s = "babad"  -> Output: "bab" (or "aba")
 * Input: s = "cbbd"   -> Output: "bb"
 *
 * Constraints:
 * 1 <= s.length <= 1000
 * s consists of only digits and English letters.
 *
 * Approaches included below:
 * 1) Brute Force: Check all substrings and test palindrome (O(n^3) time, O(1) space)
 * 2) Expand Around Center (optimal among simple approaches): O(n^2) time, O(1) space
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// -------------------
// 1. Brute Force
// -------------------
// Time: O(n^3) (O(n^2) substrings * O(n) check), Space: O(1)
class SolutionBruteForce {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        int bestL = 0, bestLen = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                if (len > bestLen && isPalindrome(s, i, j)) {
                    bestLen = len;
                    bestL = i;
                }
            }
        }
        return s.substr(bestL, bestLen);
    }
};

// -------------------
// 2. Expand Around Center (Optimal Simple Approach)
// -------------------
// Time: O(n^2), Space: O(1)
class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(string &s, int left, int right) {
        while (left >= 0 && right < (int)s.length() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        for (int i = 0; i < (int)s.length(); i++) {
            expand(s, i, i);     // odd length
            expand(s, i, i + 1); // even length
        }
        return s.substr(start, maxLen);
    }
};

/*
USAGE EXAMPLES

// Brute Force
// SolutionBruteForce sb;
// string s1 = "babad";
// cout << sb.longestPalindrome(s1) << endl; // "bab" or "aba"

// Expand Around Center
// Solution s;
// string s2 = "cbbd";
// cout << s.longestPalindrome(s2) << endl; // "bb"
*/
