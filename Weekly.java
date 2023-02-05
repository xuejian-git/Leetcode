import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;
import java.util.Stack;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collector;

class Weekly {
    public static void main(String[] args)  
	{
		System.out.println("Hello world");
        System.out.println(args); //[ljava.lang.string;@139a55  “[”代表数组， “l”代表long , "@139a55"代表哈希值
		System.out.println(args.length);  //默认长度为0
		for(int i = 0; i < args.length; i++) {
            System.out.println(args[i]); 
        }
		System.out.println("=====End=====");


        Solution test = new Solution();
        test.test();
    }

    static class Solution {
        /*
         * ------------ 语法测试 -----------------
         */
        public void test() {

            String word = "QuickRef";
            for (char c: word.toCharArray()) {
            System.out.print(c + "-");
            }
        }

        /*
         * ------------- 27场双周赛 -------------------
         */
        // 1
        public int[] separateDigits(int[] nums) {
            ArrayList<Integer> ans = new ArrayList<>();
            Stack<Integer> help = new Stack<>();
            for (int i = 0; i < nums.length; ++i) {
                int num = nums[i];
                while (num != 0) {
                    int n = num % 10;
                    num /= 10;
                    help.push(n);
                }
                while (!help.isEmpty()) {
                    ans.add(help.pop());
                }
            }
            // int[] intArr1 =  list.stream().mapToInt(Integer::valueOf).toArray();
            return ans.stream().mapToInt(Integer::valueOf).toArray();
        }
    
        // 2
        public int maxCount(int[] banned, int n, int maxSum) {
            int ans = 0, curSum = 0;
            for (int i = 1; i <= n; ++i) {
                if (!bannedHas(banned, i)) {
                    if (i + curSum <= maxSum) {
                        ans++;
                        curSum += i;
                    }
                }
            }
            return ans;
        }
        private Boolean bannedHas(int[] banned, int n ) {
            for (int i = 0; i < banned.length; i++) {
                if (banned[i] == n) {
                    return true;
                }
            }
            return false;
        }

        /*
         * -------------第332场周赛---------------------
         */
        //1
        public long pickGifts(int[] gifts, int k) {
            long ans = 0;
            PriorityQueue<Integer> g = new PriorityQueue<Integer>(Collections.reverseOrder());
            for (int i = 0; i < gifts.length; ++i) {
                g.add(gifts[i]);
            }
            for(int i = 0; i < k; i++) {
                Integer n = g.poll();
                g.add((int)Math.sqrt(n));
            }
            while (!g.isEmpty()) {
                ans += g.poll();
            }
            return ans;
        }

        //2
        public int[] vowelStrings(String[] words, int[][] queries) {
            int[] ans = new int[queries.length];
            boolean[] list = new boolean[words.length];
            for (int i = 0; i < words.length; ++i) {
                String word = words[i];
                if (isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1))) {
                    list[i] = true;
                } else {
                    list[i] = false;
                }
            }
            for (int i = 0; i < queries.length; ++i) {
                int a = 0;
                for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
                    if (list[j]) {
                        a++;
                    }
                }
                ans[i] = a;
            }
            return ans;
        }

        Boolean isVowel(Character s) {
            if (s.equals('a') || 
                s.equals('e') || 
                s.equals('i') || 
                s.equals('o') || 
                s.equals('u')
                )
                return true;
            else return false;
        }


    }
}



