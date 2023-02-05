/*
 * @lc app=leetcode.cn id=1145 lang=java
 *
 * [1145] 二叉树着色游戏
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ltnc = 0, rtnc = 0;
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        nodeCount(root, x);
        return 2 * ltnc > n || 2 * rtnc > n || 2 * (ltnc + rtnc + 1) < n;
    }
    public int nodeCount(TreeNode t, int v) {
        if (t == null) return 0;
        int lc = nodeCount(t.left, v);
        int rc = nodeCount(t.right, v);
        // 找到x选择的node，开始记录这个node的左子树和右子树的节点个数
        if (t.val == v) {
            ltnc = lc;
            rtnc = rc;
        }
        return lc + rc + 1;
    }
}
// @lc code=end

