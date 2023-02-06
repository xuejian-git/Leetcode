/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int getNext(int n) {
        int ans = 0;
        while (n != 0) {
            int a = n % 10;
            ans += a * a;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.emplace(n);
            n = getNext(n);
        }
        return n == 1;
    }
};
// @lc code=end

