/*
 * @lc app=leetcode.cn id=1807 lang=java
 *
 * [1807] 替换字符串中的括号内容
 */
import java.util.List;
import java.util.Map;
import java.util.HashMap;
// @lc code=start

class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> dict = new HashMap<String, String>();
        for (List<String> kd : knowledge) {
            dict.put(kd.get(0), kd.get(1));
        }
        String res = new String();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                String word = new String();
                i++;
                while (s.charAt(i) != ')') {
                    word += s.charAt(i);
                    i++;
                }
                res += dict.getOrDefault(word, "?");
            } else {
                res += s.charAt(i);
            }
        }
        return res;
    }
}
// @lc code=end

