
/*
 * LeetCode 6. Zigzag Conversion
 *
 * Problem Statement:
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *   string convert(string s, int numRows);
 *
 * Example 1:
 *   Input: s = "PAYPALISHIRING", numRows = 3
 *   Output: "PAHNAPLSIIGYIR"
 *
 * Example 2:
 *   Input: s = "PAYPALISHIRING", numRows = 4
 *   Output: "PINALSIGYAHRPI"
 *   Explanation:
 *   P     I    N
 *   A   L S  I G
 *   Y A   H R
 *   P     I
 *
 * Example 3:
 *   Input: s = "A", numRows = 1
 *   Output: "A"
 *
 * Constraints:
 *   - 1 <= s.length <= 1000
 *   - s consists of English letters (lower-case and upper-case), ',' and '.'
 *   - 1 <= numRows <= 1000
 *
 * Solutions:
 *   - Brute Force Approach (see zigzagConvertBruteForce)
 *   - Optimal Solution (Efficient Row-wise Construction, see Solution::convert)
 */

#include <iostream>
#include <vector>
using namespace std;


// Brute Force Approach
// Simulate the zigzag pattern by filling a 2D matrix and reading row-wise.
// Time Complexity: O(n), Space Complexity: O(n)
string zigzagConvertBruteForce(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) return s;
    vector<vector<char>> mat(numRows, vector<char>(s.length(), '\0'));
    int row = 0, col = 0;
    bool down = true;
    for (char c : s) {
        mat[row][col] = c;
        if (down) {
            if (row == numRows - 1) {
                down = false;
                row--;
                col++;
            } else {
                row++;
            }
        } else {
            if (row == 0) {
                down = true;
                row++;
            } else {
                row--;
                col++;
            }
        }
    }
    string result;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < s.length(); ++j) {
            if (mat[i][j] != '\0') result += mat[i][j];
        }
    }
    return result;
}

// Optimal Solution (Efficient Row-wise Construction)
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1 || numRows >= s.length()) return s;

       vector<string> rows(numRows);
       int currRow = 0;
       bool goingDown = false;

       for( char c : s){
        rows[currRow] +=c;
        if(currRow ==0 || currRow == numRows - 1) goingDown =! goingDown;
        currRow += goingDown ? 1 : -1;
       } 
       string result;
       for(string row: rows) result += row;

       return result;
    }
};

// Example usage
int main() {
    string s1 = "PAYPALISHIRING";
    int n1 = 3, n2 = 4;
    string s2 = "A";
    int n3 = 1;

    cout << "Brute Force (n=3): " << zigzagConvertBruteForce(s1, n1) << endl; // Output: PAHNAPLSIIGYIR
    cout << "Brute Force (n=4): " << zigzagConvertBruteForce(s1, n2) << endl; // Output: PINALSIGYAHRPI
    cout << "Brute Force (n=1): " << zigzagConvertBruteForce(s2, n3) << endl; // Output: A

    Solution sol;
    cout << "Optimal (n=3): " << sol.convert(s1, n1) << endl; // Output: PAHNAPLSIIGYIR
    cout << "Optimal (n=4): " << sol.convert(s1, n2) << endl; // Output: PINALSIGYAHRPI
    cout << "Optimal (n=1): " << sol.convert(s2, n3) << endl; // Output: A
    return 0;
}



// 0006-zigzag-conversion.cpp
// LeetCode 6. Zigzag Conversion (Optimal Solution)
// Problem: https://leetcode.com/problems/zigzag-conversion/
//
// Optimal Solution (Efficient Row-wise Construction)
//
// Time Complexity: O(n), Space Complexity: O(n)
//
// This solution is preferred for interviews and production use.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1 || numRows >= s.length()) return s;

       vector<string> rows(numRows);
       int currRow = 0;
       bool goingDown = false;

       for( char c : s){
        rows[currRow] +=c;
        if(currRow ==0 || currRow == numRows - 1) goingDown =! goingDown;
        currRow += goingDown ? 1 : -1;
       } 
       string result;
       for(string row: rows) result += row;

       return result;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 3) << endl; // Output: PAHNAPLSIIGYIR
    cout << sol.convert("PAYPALISHIRING", 4) << endl; // Output: PINALSIGYAHRPI
    cout << sol.convert("A", 1) << endl; // Output: A
    return 0;
}
