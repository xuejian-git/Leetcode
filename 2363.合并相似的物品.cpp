/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (vector<int> &item : items1) {
            mp[item[0]] += item[1];
        }
        for (vector<int> &item : items2) {
            mp[item[0]] += item[1];
        }
        vector<vector<int>> res;
        for (auto &m : mp) {
            res.push_back({m.first, m.second});
        }
        return res;
    }
};
// @lc code=end

