import java.util.Map;
import java.util.Set;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;

public class App {
    int lifeTime = 10;
	public static void main(String[] args) {
		System.out.println(args); //
        System.out.println("hello");
		//System.out.println(args.length);  //默认长度为0
        //String test = new String("{}[]{}()");
        //App app = new App();
        //app.isValid(test);
        //System.out.println(app.isValid(test));
       // new App().recursion(0);
       int[] nums = {42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40};
       
       new App().maxNumOfMarkedIndices(nums);
    }

    /*
     * 第334场周赛
     */

    //1

    public int[] leftRigthDifference(int[] nums) {
        int n = nums.length;
        int[] leftNums = new int[n];
        int[] rightNums = new int[n];
        int[] ans = new int[n];
        leftNums[0] = 0;
        rightNums[n - 1] = 0;
        for (int i = 1; i < n; ++i) {
            leftNums[i] = leftNums[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            rightNums[i] = rightNums[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = Math.abs(leftNums[i] - rightNums[i]);
        }
        return ans;
    }

    public int[] divisibilityArray(String word, int m) {
        int n = word.length();
        int[] ans = new int[n];
        long num = 0;
        for (int i = 0; i < n; i++) {
            num = num * 10 + (word.charAt(i) - '0');
            //System.out.println(word.charAt(i) - '0' + "   " + num);
            if (num % m == 0) {
                
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
        return ans;
    }

    // 3
    public int maxNumOfMarkedIndices(int[] nums) {
        int n = nums.length;
        int[] twoNums = new int[n];
        int ans = 0;
        Arrays.sort(nums);
        //Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < n; ++i) {
            System.out.println(nums[i]);
            twoNums[i] = nums[i] * 2;
            //set.add(nums[i])

        }
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if(nums[i] > twoNums[r]) {
                System.out.println(nums[i] + "   " + twoNums[r]);
                r++;
            }
        }
        //int cha = n - set.size();
        System.out.println(r);
        return (r) * 2;
    }

    // olds
    public void recursion(int i) {
        if (i < lifeTime) {
            System.out.print(i + " ");
            recursion(++i);
            System.out.print(i + "-");
        } else {
            System.out.println();
            System.out.println("reverse");
        }
    }

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
