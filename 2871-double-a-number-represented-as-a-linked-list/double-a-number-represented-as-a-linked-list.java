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
    public ListNode reverseLL(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;

        while(curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode doubleIt(ListNode head) {
        if(head == null)
            return head;

        ListNode dummy = new ListNode(0);      
        ListNode curr = reverseLL(head);
        int carry = 0;

        while(curr != null) {
            int doubleVal = curr.val + curr.val + carry;
            carry = doubleVal > 9 ? 1 : 0;

            ListNode node = new ListNode(doubleVal % 10);
            node.next = dummy.next;
            dummy.next = node;

            curr = curr.next;
        }
        if(carry != 0) {
            ListNode node = new ListNode(carry);
            node.next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
}