// LeetCode 11. Container With Most Water
// Problem Statement:
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.
//
// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:
// Input: height = [1,1]
// Output: 1
//
// Constraints:
// n == height.length
// 2 <= n <= 10^5
// 0 <= height[i] <= 10^4
//
// Approach:
// The optimal solution uses the two-pointer technique. Start with two pointers at the ends of the array and calculate the area. Move the pointer pointing to the shorter line inward, as this could potentially increase the area. Repeat until the pointers meet. This approach ensures O(n) time complexity.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            if(height[left] < height[right]){
                left++;
            } else{
                right--;
            }
        }
        return maxWater;
    }
};
