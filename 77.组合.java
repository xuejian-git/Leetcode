import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=77 lang=java
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k);
        return ans;
    }

    private void dfs(int i, int k) {
        //System.out.println(path.toString());
        // 剪枝
        int d = k - path.size(); // 还要选 d 个数
        // if (i < d) {
        //     return;
        // }
        if (i == 0) {
            if (d == 0) {
                ans.add(new ArrayList<>(path));
            }
            return;
        }


        // 不选 i
        //if (i > d)  // 枚举的第i个数 比还要选的个数大，遍历下一层
            dfs(i - 1, k);

        // 选 i
        path.add(i);
        dfs(i - 1, k);
        path.remove(path.size() - 1);
    }
}
// @lc code=end

