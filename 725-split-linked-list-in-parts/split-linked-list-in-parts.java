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
        ListNode tmp = head;
        int n = 0;

        while(tmp != null) {
            n++;
            tmp = tmp.next;
        }
        int size = n / k;
        int extra = n % k;

        ListNode[] res = new ListNode[k];
        int idx = 0, len = 1;
        tmp = head;
        
        while(tmp != null) {
            int s = size;
            if(extra > 0)
                s++;

            if(len == 1) 
                res[idx++] = tmp;
            
            if(len == s) {
                ListNode next = tmp.next;
                tmp.next = null;
                tmp = next;
                len = 1;
                extra--;
            } else {
                len++;
                tmp = tmp.next;
            }
        }

        return res;
    }
}