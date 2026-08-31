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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> stack_1 = new Stack<>();   
        Stack<Integer> stack_2 = new Stack<>();

        while(l1 != null) {
            stack_1.push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null) {
            stack_2.push(l2.val);
            l2 = l2.next;
        }

        int carry = 0;
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while((!stack_1.isEmpty()) || (!stack_2.isEmpty()) || carry != 0) {
            int sum = carry;

            if(!stack_1.isEmpty()) {
                sum += stack_1.pop();
            }
            if(!stack_2.isEmpty()) {
                sum += stack_2.pop();
            }

            carry = sum / 10;
            ListNode newn = new ListNode(sum % 10);
            newn.next = curr.next;
            curr.next = newn;
        }
        return dummy.next;
    }
}