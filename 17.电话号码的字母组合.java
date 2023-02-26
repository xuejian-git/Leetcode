import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    private static final String[] MAPPING = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> ans = new ArrayList<>();
    char[] path;

    public List<String> letterCombinations(String digits) {
        int n = digits.length();
        path = new char[n];
        if (n == 0) {
            return ans;
        }
        dfs(0, digits);
        return ans;

    }

    private void dfs(int i, String digits) {
        if (i == digits.length()) {
            ans.add(new String(path));
            return;
        }
        for (char ch : MAPPING[digits.charAt(i) - '0'].toCharArray()) {
            // 替换，不需要重置
            path[i] = ch;
            dfs(i + 1, digits);
        }
    }
}
// @lc code=end

