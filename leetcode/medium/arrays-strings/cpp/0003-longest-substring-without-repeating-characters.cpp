/*
 * Problem: Longest Substring Without Repeating Characters
 * Platform: LeetCode
 * Problem Number: 3
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Problem Statement:
 * Given a string s, find the length of the longest substring without duplicate characters.
 *
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
 *
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * Constraints:
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 * Approach: Sliding Window with Last Index Array
 * Time Complexity: O(n)
 * Space Complexity: O(1) (fixed array for ASCII)
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[256];
        for(int i = 0; i < 256; i++){
            lastIndex[i] = -1;
        }
        int left = 0;
        int maxLen = 0;
        for(int right = 0; right < s.length(); right++){
            char ch = s[right];
            if(lastIndex[ch] >= left){
                left = lastIndex[ch] + 1;
            }
            lastIndex[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

/*
USAGE EXAMPLE
// Solution sol;
// string s = "abcabcbb";
// int result = sol.lengthOfLongestSubstring(s); // result = 3
*/
