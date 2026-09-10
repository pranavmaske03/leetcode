/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        List<List<Integer>> result = new ArrayList<>();
        
        while(!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> row = new ArrayList<>();

            for(int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                row.add(node.val);

                if(node.left != null)
                    queue.offer(node.left);
                if(node.right != null) {
                    queue.offer(node.right);
                }
            }
            result.add(row);
        }
        return result;
    }
}