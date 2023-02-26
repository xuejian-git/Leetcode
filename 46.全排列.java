/*
 * @lc app=leetcode.cn id=46 lang=java
 *
 * [46] 全排列
 */
import java.util.Set;
import java.util.List;
import java.util.ArrayList;
import java.util.HashSet;
// @lc code=start
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();
    boolean[] used;
    private int n;
    int count = 0;
    public List<List<Integer>> permute(int[] nums) {
        this.n = nums.length;
        used = new boolean[n];
        dfs(0, used, nums);
        return ans;
    }

    private void dfs(int i, boolean[] used, int[] nums){
        System.out.println(count++);
        if (i == n) {
            ans.add(new ArrayList<Integer>(path));
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                path.add(nums[j]);
                used[j] = true;

                dfs(i + 1, used, nums);

                path.remove(path.size() - 1);
                used[j] = false;
            }
        }
    }
}
// @lc code=end

