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
    public ListNode mergeKLists(ListNode[] lists) {
        List<ListNode> nodes = new ArrayList<>();

        for(ListNode list : lists) {
            ListNode curr = list;
            while(curr != null) {
                nodes.add(curr);
                curr = curr.next;
            }
        }
        if(nodes.isEmpty()) 
            return null;
        nodes.sort((a, b) -> Integer.compare(a.val, b.val));

        int n = nodes.size();
        for (int i = 0; i < n - 1; i++) {
            nodes.get(i).next = nodes.get(i + 1);
        }
        nodes.get(n - 1).next = null;

        return nodes.get(0);
    }
}