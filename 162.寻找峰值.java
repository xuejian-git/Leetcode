/*
 * @lc app=leetcode.cn id=162 lang=java
 *
 * [162] 寻找峰值
 */
/*
 * 输入：nums = [1,2,1,3,5,6,4]
 * 输出：1 或 5 
 */
// @lc code=start
class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + r >> 1;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
}
// @lc code=end

