import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=2287 lang=java
 *
 * [2287] 重排字符形成目标字符串
 */
import java.util.Map;
import java.lang.Math;
// @lc code=start
class Solution {
    public int rearrangeCharacters(String s, String target) {
        Map<Character, Integer> sCounts = new HashMap<Character, Integer>();
        Map<Character, Integer> targetCounts = new HashMap<Character, Integer>();
        int n = s.length(), m = target.length();
        for (int i = 0; i < m; i++) {
            char ch = target.charAt(i);
            targetCounts.put(ch, targetCounts.getOrDefault(ch, 0) + 1);
        }
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (targetCounts.containsKey(ch)) {
                sCounts.put(ch, sCounts.getOrDefault(ch, 0) + 1);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (Map.Entry<Character, Integer> entry : targetCounts.entrySet()) {
            char ch = entry.getKey();
            int count = entry.getValue();
            int totalCount = sCounts.containsKey(ch) ? sCounts.get(ch) : 0;
            if (totalCount == 0) {
                return 0;
            }
            ans = Math.min(ans, totalCount / count);
        }
        return ans;
    }
}
// @lc code=end

