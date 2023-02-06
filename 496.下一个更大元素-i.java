/*
 * @lc app=leetcode.cn id=496 lang=java
 *
 * [496] 下一个更大元素 I
 */
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
// @lc code=start
class Solution {
    // 单调栈:找到最近一个比其大的元素
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        int n = nums2.length;
        for (int i = n - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!stack.isEmpty() && num >= stack.peek()) {
                stack.pop();
            }
            map.put(num, stack.isEmpty() ? -1 : stack.peek());
            stack.push(num);
        }
        int[] ans = new int[nums1.length];
        int m = nums1.length;
        for (int i = 0; i < m; i++) {
            ans[i] = map.get(nums1[i]);
        }
        return ans;
    }
}
// @lc code=end

