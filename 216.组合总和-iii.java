import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=216 lang=java
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(9, k, n);
        return ans;
    }
    /*
     * i ~ 1 中选k个数，和为t
     */
    private void dfs(int i, int k, int t) {
        int d = k - path.size(); // 还要选d个数
        /*
         * 剪枝
         * 0. 剩余数目不够 i < d
         * 1. t < 0
         * 2. 剩余数字全选最大 < t
         */
        if (i < d || t < 0 || t > (i + i - d + 1) * d / 2) {
            return;
        }
        if (d == 0) {
            ans.add(new ArrayList<>(path));
            return;
        }

        for (int j = i; j > 0; j--) {
            path.add(j);
            dfs(j - 1, k, t - j);
            path.remove(path.size() - 1);
        }
    }
}
// @lc code=end

