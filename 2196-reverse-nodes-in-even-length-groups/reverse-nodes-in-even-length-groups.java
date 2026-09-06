class Solution {
    public ListNode reverseLL(ListNode first, ListNode last) {
        ListNode prev = last;
        while(first != last) {
            ListNode next = first.next;
            first.next = prev;
            prev = first;
            first = next;
        }
        return prev;
    }


    public ListNode reverseEvenLengthGroups(ListNode head) {
        int groupSize = 1;
        ListNode curr = head;
        ListNode manage = head;

        while(curr != null) {
            ListNode first = curr;
            ListNode last = null;
            int len = 0;

            while(curr != null && len < groupSize) {
                last = curr;
                curr = curr.next;
                len++;
            }

            if(len % 2 == 0) {
                ListNode newHead = reverseLL(first, curr);
                manage.next = newHead;
                manage = first;
            } else {
                manage = last;
            }
            groupSize++;
        }
        return head;
    }
}