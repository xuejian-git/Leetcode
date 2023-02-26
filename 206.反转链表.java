/*
 * @lc app=leetcode.cn id=206 lang=java
 *
 * [206] 反转链表
 */
// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        // ListNode dummy = new ListNode(0, head);
        // while (head != null && head.next != null) {
        //     ListNode temp = dummy.next;
        //     ListNode tempNext = head.next;
        //         dummy.next = tempNext;
        //         head.next = tempNext.next;
        //         tempNext.next = temp;
        // }
        // return dummy.next;
        if (head == null || head.next == null) {
            return head;
        }
        ListNode newNode = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newNode;
    }
}
// @lc code=end

