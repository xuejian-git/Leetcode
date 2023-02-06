import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=1805 lang=java
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> set = new HashSet<>();
        int n = word.length(), p1 = 0, p2;
        while (true) {
            while (p1 < n && !Character.isDigit(word.charAt(p1))) {
                p1++;
            }
            if (p1 == n) break;
            p2 = p1;
            while (p2 < n && Character.isDigit(word.charAt(p2))) {
                p2++;
            }
            while (p2 > p1 && word.charAt(p1) == '0') {
                p1++;
            }
            set.add(word.substring(p1, p2));
            p1 = p2;
        }
        return set.size();
    }
}
// @lc code=end

