/*
 * @lc app=leetcode.cn id=1456 lang=java
 *
 * [1456] 定长子串中元音的最大数目
 */
import java.lang.Character;
import java.util.HashSet;
import java.util.Set;
// @lc code=start
class Solution {
    public int maxVowels(String s, int k) {
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        
        int n = s.length();
        int vow_count = 0;
        for (int i = 0; i < k; ++i) {
            if (vowels.contains(s.charAt(i))) vow_count += 1;
        }
        int ans = vow_count;
        for (int i = k; i < n; ++i) {
            if (vowels.contains(s.charAt(i))) vow_count += 1;
            if (vowels.contains(s.charAt(i - k))) vow_count -= 1;
            ans = Math.max(ans, vow_count);
        }
        return ans;

    }
}
// @lc code=end

