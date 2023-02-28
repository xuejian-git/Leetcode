/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        // dfs
        function<int(int)> dfs = [&] (int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (cache[i] != -1) {
                return cache[i];
            } 
            int ans = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            cache[i] = ans;
            return ans;
        };

        return dfs(n - 1);
    }
};
// @lc code=end

