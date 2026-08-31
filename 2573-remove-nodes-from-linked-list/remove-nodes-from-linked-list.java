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
    public ListNode removeNodes(ListNode head) {
        Stack<Integer> stack = new Stack<>();

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        ListNode tmp = head;
        while(tmp != null) {
            while(!stack.isEmpty() && stack.peek() < tmp.val) {
                stack.pop();
            }
            stack.push(tmp.val);
            tmp = tmp.next;
        }
        while(!stack.empty()) {
            ListNode newn = new ListNode(stack.pop());
            newn.next = curr.next;
            curr.next = newn;
        }
        return dummy.next;
    }
}