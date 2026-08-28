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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null)
            return null;
        
        int totalNodes = 0;
        ListNode curr = head;
        ListNode prev = head;

        while(curr != null) {
            if(totalNodes > n) prev = prev.next;
            totalNodes++;
            curr = curr.next;
        }

        if(totalNodes == n) return prev.next;
        else prev.next = prev.next.next;

        return head;
    }
}