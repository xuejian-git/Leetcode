/*
 * @lc app=leetcode.cn id=509 lang=java
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
    public int fib(int n) {
        if ( n == 0 || n == 1) {
            return n == 1 ? 1 : 0;
        }
        return fib(n - 1) + fib(n - 2);
    }
}
// @lc code=end

