/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int f = 0, cnt_b = 0;
        for (char c : s)
            if (c == 'b') ++cnt_b; // f 值不变
            else f = min(f + 1, cnt_b);
        return f;
    }
};
// @lc code=end

