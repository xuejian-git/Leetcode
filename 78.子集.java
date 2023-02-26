import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=78 lang=java
 *
 * [78] 子集
 */
import java.util.List;
import java.util.ArrayList;
// @lc code=start
class Solution {
    List<Integer> t = new ArrayList<>();
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> subsets(int[] nums) {
        dfs(0, nums);
        return res;
    }
    // 答案角度：枚举下一个 i>=cur 的数字
    private void dfs(int cur, int[] nums) {
        res.add(new ArrayList<Integer>(t));
        if (cur == nums.length) {
            return;
        }

        for (int i = cur; i < nums.length; i++) {
            t.add(nums[i]);
            dfs(i + 1, nums);
            t.remove(t.size() - 1);
        }  
    }
}
// @lc code=end

