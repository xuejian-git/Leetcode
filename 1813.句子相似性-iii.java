/*
 * @lc app=leetcode.cn id=1813 lang=java
 *
 * [1813] 句子相似性 III
 */
import java.lang.String;
import java.util.Arrays;
// @lc code=start
class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");

        int i = 0, j = 0;
        System.out.println("words1[i] == words2[i]  " + words1[i] == words2[i]);
        while (i < words1.length && i < words2.length && words1[i].equals(words2[i])) {
            i++;
        }
        while (i + j < words1.length && i + j < words2.length && 
                words1[words1.length - j - 1].equals(words2[words2.length - j -1])) {
            j++;
        }
        System.out.println("i j :" + i + " " + j);
        return i + j == Math.min(words1.length, words2.length);
    }
}
// @lc code=end

