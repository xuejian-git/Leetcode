/*
 * @lc app=leetcode.cn id=344 lang=java
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
    public void reverseString(char[] s) {
      // 1.双指针
      // 2.递归
      recursion(s, 0, s.length - 1); 
    }

    private void recursion(char[] s, int left, int right) {
        if (left >= right) {
            return;
        }
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        recursion(s, left + 1, right - 1);
    }
}
// @lc code=end

