/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> mp = new HashMap<>();

        Node dummy = new Node(0);
        Node curr = head;
        Node tmp = dummy;

        while(curr != null) {
            tmp.next = new Node(curr.val);
            mp.put(curr, tmp.next);
            curr = curr.next;
            tmp = tmp.next;
        }

        curr = head;
        tmp = dummy.next;
        while(curr != null) {
            if(curr.random != null) {
                tmp.random = mp.get(curr.random);
            }
            curr = curr.next;
            tmp = tmp.next;
        }
        return dummy.next;
    }
}