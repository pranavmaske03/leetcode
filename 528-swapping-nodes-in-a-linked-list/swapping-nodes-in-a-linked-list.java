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
    public ListNode swapNodes(ListNode head, int k) {
        if(head == null || head.next == null)   
            return head;
        
        int totalNodes = 0;
        ListNode _curr = head;
        ListNode _first = head, _last = head;

        while(_curr != null) {
            if(++totalNodes < k) _first = _first.next;
            if(totalNodes > k) _last = _last.next;

            _curr = _curr.next; 
        }

        int temp = _first.val;
        _first.val = _last.val;
        _last.val = temp;

        return head;
    }
}