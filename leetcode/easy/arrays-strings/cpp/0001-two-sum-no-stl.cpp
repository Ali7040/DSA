/*
 * Problem: Two Sum
 * Platform: LeetCode
 * Problem Number: 1
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/
 *
 * Problem Statement:
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Approaches:
 * 1. Brute Force (Nested Loops)
 *    - Time: O(n^2)
 *    - Space: O(1)
 * 2. Hash Map (STL)
 *    - Time: O(n)
 *    - Space: O(n)
 * 3. Custom Hash Map (No STL, No Library)
 *    - Time: O(n)
 *    - Space: O(1) (fixed array)
 *
 * See below for all three solutions.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// -------------------
// 1. Brute Force
// -------------------
// Time: O(n^2), Space: O(1)
class SolutionBruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// -------------------
// 2. Hash Map (STL)
// -------------------
// Time: O(n), Space: O(n)
class SolutionHashMap {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

// -------------------
// 3. Custom Hash Map (No STL, No Library)
// -------------------
// Time: O(n), Space: O(1) (fixed array)
class SolutionNoSTL {
public:
    static const int SIZE = 20001; // covers -10000 to +10000
    int hash[SIZE];
    bool used[SIZE];

    int getHash(int key) {
        return key + 10000; // shift negative values
    }

    // nums: input array, n: size of array, target: target sum
    // result: output array of size 2 (indices), returns true if found
    bool twoSum(int* nums, int n, int target, int* result) {
        for (int i = 0; i < SIZE; i++)
            used[i] = false;
        for (int i = 0; i < n; i++) {
            int need = target - nums[i];
            int h = getHash(need);
            if (used[h]) {
                result[0] = hash[h];
                result[1] = i;
                return true;
            }
            int idx = getHash(nums[i]);
            used[idx] = true;
            hash[idx] = i;
        }
        return false;
    }
};

/*
USAGE EXAMPLES

// 1. Brute Force
// SolutionBruteForce sol1;
// vector<int> nums = {2, 7, 11, 15};
// int target = 9;
// auto result1 = sol1.twoSum(nums, target); // result1 = {0, 1}

// 2. Hash Map (STL)
// SolutionHashMap sol2;
// vector<int> nums = {2, 7, 11, 15};
// int target = 9;
// auto result2 = sol2.twoSum(nums, target); // result2 = {0, 1}

// 3. Custom Hash Map (No STL)
// SolutionNoSTL sol3;
// int nums[] = {2, 7, 11, 15};
// int n = 4;
// int target = 9;
// int result3[2];
// if (sol3.twoSum(nums, n, target, result3)) {
//     cout << result3[0] << " " << result3[1] << endl; // Output: 0 1
// } else {
//     cout << "No solution found" << endl;
// }
*/
