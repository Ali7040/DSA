/*
 * Problem: Median of Two Sorted Arrays
 * Platform: LeetCode
 * Problem Number: 4
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Problem Statement:
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 * Example 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 * Constraints:
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 * Approaches:
 * 1. Brute Force (Merge and Find Median)
 *    - Time: O(m + n)
 *    - Space: O(m + n)
 * 2. Binary Search (Optimal)
 *    - Time: O(log(min(m, n)))
 *    - Space: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 1. Brute Force Solution
class SolutionBruteForce {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while (i < nums1.size()) merged.push_back(nums1[i++]);
        while (j < nums2.size()) merged.push_back(nums2[j++]);
        int n = merged.size();
        if (n % 2 == 1) return merged[n / 2];
        else return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
};

// 2. Optimal Solution (Binary Search)
class SolutionOptimal {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        int low = 0, high = n;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;
            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n) ? INT_MAX : nums1[i];
            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == m) ? INT_MAX : nums2[j];
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if (left1 > right2) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};

/*
USAGE EXAMPLES
// SolutionBruteForce sol1;
// vector<int> nums1 = {1, 3};
// vector<int> nums2 = {2};
// double result1 = sol1.findMedianSortedArrays(nums1, nums2); // result1 = 2.0

// SolutionOptimal sol2;
// vector<int> nums1 = {1, 2};
// vector<int> nums2 = {3, 4};
// double result2 = sol2.findMedianSortedArrays(nums1, nums2); // result2 = 2.5
*/
