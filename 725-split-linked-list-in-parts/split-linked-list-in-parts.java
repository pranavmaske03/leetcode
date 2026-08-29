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
        int totalNodes = 0;

        while(tmp != null) {
            totalNodes++;
            tmp = tmp.next;
        }

        int quotient = totalNodes / k;
        int remaining = totalNodes % k;
        
        int[] count = new int[k];
        Arrays.fill(count, quotient);

        for(int i = remaining - 1; i >= 0; i--) {
            count[i]++;
        }

        ListNode[] res = new ListNode[k];
        tmp = head;
        for(int i = 0; i < k; i++) {
            res[i] = tmp;
            for(int j = 1; j < count[i]; j++) {
                tmp = tmp.next;
            }
            if(tmp != null) {
                ListNode next = tmp.next;
                tmp.next = null;
                tmp = next;
            }
        }
        return res;
    }
}