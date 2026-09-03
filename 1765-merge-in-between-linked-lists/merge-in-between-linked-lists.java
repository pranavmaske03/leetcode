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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
                
        ListNode before = list1;
        for(int i = 0; i < a-1; i++)
            before = before.next;
    
        ListNode after = before.next;
        for(int i = 0; i <= b-a; i++)
            after = after.next;
    
        ListNode last = list2;
        while(last.next != null)
            last = last.next;
        
        before.next = list2;
        last.next = after;
        return list1;
    }
}