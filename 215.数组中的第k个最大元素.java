/*
 * @lc app=leetcode.cn id=215 lang=java
 *
 * [215] 数组中的第K个最大元素
 */
import java.util.PriorityQueue;
import java.util.Collections;
// @lc code=start
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pQueue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++) {
            pQueue.add(nums[i]);
        }
        while(k > 1) {
            pQueue.poll();
            k--;
        }
        return pQueue.peek();
    }
}
// @lc code=end

