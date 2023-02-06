/*
 * @lc app=leetcode.cn id=1945 lang=java
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution {
    public int getLucky(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            sb.append(ch - 'a' + 1);
        }
        String digits = sb.toString();
        for (int i = 0; i < k && digits.length() != 1; i++) {
            int sum = 0;
            for (int j = 0; j < digits.length(); j++) {
                sum += digits.charAt(j) - '0';
            }
            digits = Integer.toString(sum);
        }
        return Integer.parseInt(digits);
    }
}
// @lc code=end

