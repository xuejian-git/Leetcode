import java.util.Map;
import java.util.HashMap;
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
    }

    
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
