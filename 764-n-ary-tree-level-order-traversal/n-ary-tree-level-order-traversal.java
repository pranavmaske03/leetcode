/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if(root == null)       
            return new ArrayList<>();
        
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        List<List<Integer>> result = new ArrayList<>();
        int level = 0;

        while(!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> row = new ArrayList<>();

            for(int i = 0; i < levelSize; i++) {
                Node node = queue.poll();
                row.add(node.val);

                for(Node child : node.children) {
                    queue.offer(child);
                }
            }
            result.add(row);
        }
        return result;
    }
}