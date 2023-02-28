/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int s[] = {0, 0};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int left = i > 0 ? nums[i - 1] : INT_MAX;
            int right = i < n - 1 ? nums[i + 1] : INT_MAX;
            s[i % 2] += max(nums[i] - min(left, right) + 1, 0);
        }
        return min(s[0], s[1]);
    }
};
// @lc code=end

