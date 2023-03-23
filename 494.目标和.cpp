/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {

public:
    /*
     * 正数和 p
     * 则 负数和 s - p (nums 和为 s)
     * 则 p - (s - p) = target
     * 则 p = (t + s) / 2 的方案数
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2) {
            cout << "enter" << endl;
            return 0;
        }
        target /= 2;

        //dfs
        // int n = nums.size();
        // function<int(int, int)> dfs = [&](int i, int c) {
        //     if (i < 0) {
        //         return c == 0 ? 1 : 0;
        //     }
        //     if (c < nums[i]) {
        //         return dfs(i - 1, c);
        //     }
        //     return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        // };

        // return dfs(n - 1,target);
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= target; ++c) {
                if (c < nums[i]) f[i + 1][c] = f[i][c];
                else f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
            }
        }
        return f[n][target];
    }
};
// @lc code=end

