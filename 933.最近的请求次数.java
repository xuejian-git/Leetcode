import java.util.LinkedList;
import java.util.Queue;

import javax.swing.text.html.HTMLDocument.RunElement;

/*
 * @lc app=leetcode.cn id=933 lang=java
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter {
    Queue<Integer> count;
    public RecentCounter() {
        count = new LinkedList<>();
    }
    
    public int ping(int t) {
        count.add(t);
        while (t - 3000 > count.peek()) {
            // 把队首的都删掉，还剩的就是最近3000ms的请求数
            count.poll();
        }
        return count.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
// @lc code=end

