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

        while(head != null) {
            ListNode node = head.next;
            while(node != null && node.val == head.val) {
                node = node.next;
            }

            if(head.next != node) {
                prev.next = node;
            } else {
                prev = head;
            }
            head = node;
        }
        return dummy.next;
    }
}