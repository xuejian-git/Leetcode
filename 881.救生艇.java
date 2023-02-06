/*
 * @lc app=leetcode.cn id=881 lang=java
 *
 * [881] 救生艇
 */
import java.util.Arrays;
// @lc code=start
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int boatsNum = 0;
        Arrays.sort(people);
        int start = 0, end = people.length - 1;
        while (start <= end) {
            if (people[start] + people[end] <= limit) {
                start++;
            }
            end--;
            boatsNum++;
        }
        return boatsNum;
    }
}
// @lc code=end

