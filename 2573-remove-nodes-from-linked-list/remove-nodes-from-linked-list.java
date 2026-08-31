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
        Stack<ListNode> stack = new Stack<>();

        ListNode curr = head;
        while(curr != null) {
            while(!stack.isEmpty() && stack.peek().val < curr.val) {
                stack.pop();
            }
            stack.push(curr);
            curr = curr.next;
        }
        ListNode prev = null;
        while(!stack.empty()) {
            ListNode node = stack.pop();
            node.next = prev;
            prev = node;
        }
        return prev;
    }
}