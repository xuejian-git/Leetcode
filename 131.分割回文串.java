/*
 * @lc app=leetcode.cn id=131 lang=java
 *
 * [131] 分割回文串
 */
import java.util.ArrayList;
import java.util.List;
// @lc code=start
class Solution {
    List<String> path = new ArrayList<>();
    List<List<String>> res = new ArrayList<>();
    public List<List<String>> partition(String s) {
        dfs(0, s);
        return res;
    }

    private boolean isPalindrome(int left, int right, String s) {
        while (left < right)
            if (s.charAt(left++) != s.charAt(right--))
                return false;
        return true;
    }

    // 答案角度：枚举下一个 j>=i 的字母
    private void dfs(int i, String s) {
        if (i == s.length()) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (isPalindrome(i, j, s)) {
                path.add(s.substring(i, j + 1));
                dfs(j + 1, s);
                path.remove(path.size() - 1);
            }
        }
    }
}
// @lc code=end

