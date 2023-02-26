import javax.lang.model.util.ElementScanner14;

/*
 * @lc app=leetcode.cn id=74 lang=java
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                //在这行
                System.out.println("enter");
                int l = 0, r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int num = matrix[i][mid];
                    System.out.println(mid + " " + num);
                    if (target == num) {
                        return true;
                    } else if (target < num) {
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                return false;
            } else if (target < matrix[i][0]) {
                return false;
            }
        }
        return false;
    }
}
// @lc code=end

