/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        // f(i) 代表以第 i 个数结尾的「连续子数组的最大和」
        int pre = 0, maxSum = nums[0];
        for (int num : nums) {
            pre = Math.max(pre + num, num);
            maxSum = Math.max(pre, maxSum);
        }
        return maxSum;
    }
}
// @lc code=end

