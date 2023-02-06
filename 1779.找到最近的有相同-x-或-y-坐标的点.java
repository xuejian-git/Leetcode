/*
 * @lc app=leetcode.cn id=1779 lang=java
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int ans = -1, mi = 1000000;
        for (int i = 0; i < points.length; ++i) {
            int a = points[i][0], b = points[i][1];
            if (a == x || b == y) {
                int d = Math.abs(a - x) + Math.abs(b - y);
                if (d < mi) {
                    mi = d;
                    ans = i;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

