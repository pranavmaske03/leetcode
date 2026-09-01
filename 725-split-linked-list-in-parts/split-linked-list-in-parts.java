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
    public ListNode[] splitListToParts(ListNode head, int k) {       
        int totalNodes = 0;
        ListNode _curr = head;
        
        while(_curr != null) {
            totalNodes++;
            _curr = _curr.next;
        }

        int size = totalNodes / k;
        int extra = totalNodes % k;

        ListNode[] result = new ListNode[k];
        ListNode tmp = head;
        for(int i = 0; i < k; i++) {
            result[i] = tmp;
            int n = (extra > 0) ? size + 1 : size;

            for(int j = 1; j < n; j++)    
                tmp = tmp.next;
            
            if(tmp != null) {
                ListNode next = tmp.next;
                tmp.next = null;
                tmp = next;
                --extra;
            }
        }
        return result;
    }
}