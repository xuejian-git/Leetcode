import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=1819 lang=java
 *
 * [1819] 序列中不同最大公约数的数目
 */
// @lc code=start
// class Solution {
//     public int differenceOfSum(int[] nums) {
//         int sum = 0;
//         int sum1 = 0;
//         for (int i = 0; i < nums.length; i++) {
//             int n = nums[i];
//             sum += n;
//             while (n != 0) {
//                 sum1 += n % 10;
//                 n = n / 10;
//             } 
//         }
//         return Math.abs(sum - sum1);
        
//     }
// }
// class Solution {
//     public int[][] rangeAddQueries(int n, int[][] queries) {
//         int[][] ans = new int[n][n];
//         for (int i = 0 ; i < queries.length; i++) {
//             int[] querie = queries[i];
//             for (int j = querie[0]; j <= querie[2]; j++) {
//                 for (int k =  querie[1]; k <= querie[3]; k++) {
//                     ans[j][k]++;
//                 }
//             }
//         }
//         return ans;
//     }
// }
/* 
class Solution {
    //nums = [3,1,4,3,2,2,4], k = 2
    public long countGood(int[] nums, int k) {
        if (k >= nums.length) return 1;
        long ans = 0;
        
        for(int start = 0; start < nums.length; start++) {
            int count = 0;
            Set<Integer> subNums = new HashSet<>();
            subNums.add(nums[start]);
            for (int end = start; end < nums.length; end++) {
                if (subNums.contains(nums[end])) {
                    count++;
                    if (count >= k) {
                        ans++;
                    }
                } else {
                    subNums.add(nums[end]);
                }

            }

        }
        return ans;
    }
*/
class Solution {
    //nums = [3,1,4,3,2,2,4], k = 2
    public long countGood(int[] nums, int k) {
        if (k >= nums.length) return 1;
        long ans = 0;
        
        for(int start = 0; start < nums.length; start++) {
            int count = 0;
            for (int end = start + 1; end < nums.length; end++) {

                for (int i = start; i <= end; i++)  {
                    for (int j = start + 1; j <= end; j++)  {
                        if (nums[i] == nums[j]) {
                            count++;
                            if (count >= k) {
                                System.out.println("s , e" + start + end);
                                ans++;
                            }
                        }
                    }
                }

            }

        }
        return ans;
    }
}
// @lc code=end

