/*
 * LeetCode 7. Reverse Integer
 *
 * Problem Statement:
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 *
 * Example 1:
 *   Input: x = 123
 *   Output: 321
 * Example 2:
 *   Input: x = -123
 *   Output: -321
 * Example 3:
 *   Input: x = 120
 *   Output: 21
 * Example 4:
 *   Input: x = 0
 *   Output: 0
 *
 * Constraints:
 *   -2^31 <= x <= 2^31 - 1
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int digit = 0;
        while (x != 0) {
            digit = x % 10;
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.reverse(123) << endl;    // Output: 321
    cout << sol.reverse(-123) << endl;   // Output: -321
    cout << sol.reverse(120) << endl;    // Output: 21
    cout << sol.reverse(0) << endl;      // Output: 0
    return 0;
}
