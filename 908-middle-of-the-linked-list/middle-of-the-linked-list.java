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
    public ListNode middleNode(ListNode head) {
        ListNode _slow = head;
        ListNode _fast = head;

        while(_fast != null && _fast.next != null) {
            _slow = _slow.next;
            _fast = _fast.next.next;
        }

        return _slow;
    }
}