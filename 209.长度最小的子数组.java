/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
    public int minSubArrayLen(int target, int[] nums) {

        int minLen = Integer.MAX_VALUE;
        // 窗口[l, r]
        int l = 0, r = 0;
        int sum = 0;
        while (r < nums.length) {
            sum += nums[r];
            while (sum >= target) {
                minLen = Math.min(minLen, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }
        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
}
// @lc code=end

