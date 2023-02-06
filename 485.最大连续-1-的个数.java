import java.util.ArrayList;

/*
 * @lc app=leetcode.cn id=485 lang=java
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        int res = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                res = Math.max(count, res);
                count = 0;
            }
        }
        res = Math.max(count, res);
        return res;
    }
}
// @lc code=end

