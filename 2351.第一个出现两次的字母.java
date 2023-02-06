import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=2351 lang=java
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution {
    public char repeatedCharacter(String s) {
        Set<Character> ch = new HashSet<Character>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            
            if (!ch.add(c)) {
                return c;
            }
        }
        return ' ';
    }
}
// @lc code=end

