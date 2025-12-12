/*
 * Problem: Valid Parentheses
 * Platform: LeetCode
 * Problem Number: 20
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-parentheses/
 * 
 * Problem Statement:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 * 
 * Approach 1: Array-based Stack
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(n) for the stack array
 * 
 * Approach 2: STL Stack
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(n) for the stack
 * 
 * Optimal Solution: Both approaches have the same time and space complexity.
 * Array-based approach is slightly more memory efficient but has a fixed size limit.
 * STL stack is more flexible and safer. Approach 1 is shown as the main solution.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Approach 1: Array-based Stack
    // Time: O(n) - single pass through the string
    // Space: O(n) - worst case all characters are opening brackets
    bool isValid(string s) {
        char stack[10000];
        int top = -1;
        
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i]; // read the char one by one from string
            
            if(ch == '(' || ch == '{' || ch == '[') {
                // Push opening bracket onto stack
                stack[++top] = ch;
            } else {
                // If stack is empty, no matching opening bracket
                if(top == -1) return false;
                
                // Pop and check if it matches
                char topChar = stack[top--];
                
                if((ch == ')' && topChar != '(') ||
                   (ch == '}' && topChar != '{') ||
                   (ch == ']' && topChar != '[')) {
                    return false;
                }
            }
        }
        
        // Stack should be empty if all brackets are matched
        return top == -1;
    }
    
    // Approach 2: Using STL Stack (Alternative)
    // Time: O(n) - single pass through the string
    // Space: O(n) - worst case all characters are opening brackets
    bool isValidSTL(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // If stack is empty, no matching opening bracket
                if(st.empty()) return false;
                
                char topChar = st.top();
                st.pop();
                
                // Check if closing bracket matches opening bracket
                if((ch == ')' && topChar != '(') ||
                   (ch == '}' && topChar != '{') ||
                   (ch == ']' && topChar != '[')) {
                    return false;
                }
            }
        }
        
        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    // Test cases
    // Test 1: Simple valid parentheses
    // Input: "()"
    // Expected: true
    cout << "Test 1: \"()\" -> " << (sol.isValid("()") ? "true" : "false") << endl;
    
    // Test 2: Multiple valid bracket types
    // Input: "()[]{}"
    // Expected: true
    cout << "Test 2: \"()[]{}\" -> " << (sol.isValid("()[]{}") ? "true" : "false") << endl;
    
    // Test 3: Invalid - mismatched brackets
    // Input: "(]"
    // Expected: false
    cout << "Test 3: \"(]\" -> " << (sol.isValid("(]") ? "true" : "false") << endl;
    
    // Test 4: Nested valid brackets
    // Input: "([])"
    // Expected: true
    cout << "Test 4: \"([])\" -> " << (sol.isValid("([])") ? "true" : "false") << endl;
    
    // Test 5: Invalid - wrong order
    // Input: "([)]"
    // Expected: false
    cout << "Test 5: \"([)]\" -> " << (sol.isValid("([)]") ? "true" : "false") << endl;
    
    // Test 6: Empty string
    // Input: ""
    // Expected: true
    cout << "Test 6: \"\" -> " << (sol.isValid("") ? "true" : "false") << endl;
    
    // Test 7: Only opening brackets
    // Input: "((("
    // Expected: false
    cout << "Test 7: \"(((\" -> " << (sol.isValid("(((") ? "true" : "false") << endl;
    
    // Test 8: Only closing brackets
    // Input: ")))"
    // Expected: false
    cout << "Test 8: \")))\" -> " << (sol.isValid(")))") ? "true" : "false") << endl;
    
    return 0;
}

/*
 * Explanation:
 * 
 * This problem is a classic stack application. The key insight is that we need to
 * match closing brackets with the most recent opening bracket of the same type.
 * 
 * Algorithm:
 * 1. Iterate through each character in the string
 * 2. If it's an opening bracket, push it onto the stack
 * 3. If it's a closing bracket:
 *    - Check if stack is empty (return false if empty)
 *    - Pop the top element and check if it matches
 *    - Return false if it doesn't match
 * 4. After processing all characters, check if stack is empty
 * 
 * Why Stack?
 * - We need LIFO (Last In First Out) behavior
 * - The most recent opening bracket must match the current closing bracket
 * - Stack perfectly models this requirement
 * 
 * Complexity Analysis:
 * - Time: O(n) - we visit each character exactly once
 * - Space: O(n) - in worst case (all opening brackets), stack stores all n characters
 * 
 * Edge Cases:
 * - Empty string (valid - return true)
 * - Only opening brackets (invalid - return false)
 * - Only closing brackets (invalid - return false)
 * - Mismatched brackets (invalid - return false)
 * - Nested brackets (valid if properly matched)
 * 
 * Comparison of Approaches:
 * - Array-based: More memory efficient, but has fixed size limit (10000 in this case)
 * - STL Stack: More flexible, no size limit, safer, but slightly more overhead
 * 
 * Both are optimal in terms of time complexity. Choose based on constraints:
 * - If string length is guaranteed to be < 10000: Array-based is fine
 * - If string length can be very large: Use STL stack
 */

