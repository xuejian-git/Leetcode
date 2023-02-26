import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    private List<String> ans = new ArrayList<>();
    private char[] path;
    private int n;
    public List<String> generateParenthesis(int n) {
        this.n = n;
        path = new char[2 * n];
        // dfs
        dfs(0, 0);
        return ans;
    }

    private void dfs(int i, int open) {
        // 返回条件
        if (i == 2 * n) {
            ans.add(new String(path));
        }

        if (open < n) { // 可以填左括号
            path[i] = '(';
            dfs(i + 1, open + 1);
        }
        if (i - open < open) { // 可以填右括号
            path[i] = ')';
            dfs(i + 1, open);
        }
    }
}
// @lc code=end

