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
    public ListNode reverseLL(ListNode curr, ListNode last) {
        ListNode prev = null;

        while(prev != last) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return last;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || head.next == null || k == 1) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        ListNode manage = dummy;
        ListNode curr = head;
        ListNode first = null;

        int count = 0;
        while(curr != null) {
            if(count == 0) 
                first = curr;

            ListNode next = curr.next;
            count++;

            if(count == k) {
                manage.next = reverseLL(first, curr);
                manage = first;
                count = 0;
            }
            curr = next;
        }
        if(count != 0) {
            manage.next = first;
        }
        return dummy.next;
    }
}