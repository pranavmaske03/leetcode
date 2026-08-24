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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null)
            return head;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        ListNode curr = head;

        while(curr != null) {
            ListNode node = curr.next;

            while(node != null && node.val == curr.val) {
                node = node.next;
            }

            if(curr.next != node) {
                prev.next = node;
            } else {
                prev = curr;
            }
            curr = node;
        }
        return dummy.next;
    }
}