import java.util.HashMap;
import java.util.Stack;

/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */
import java.util.Map;
// @lc code=start
class Solution {
    
    public boolean isValid(String s) {
        Map<Character, Character> bracket = new HashMap<Character, Character>(){{
            put(')', '(');
            put(']', '[');
            put('}', '{');}};
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '['|| ch == '{') {
                stack.push(s.charAt(i));
            } else {
                if (stack.isEmpty() || stack.peek() != bracket.get(ch)) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
// @lc code=end

