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
    public List<Double> averageOfLevels(TreeNode root) {
        if(root == null)       
            return null;
        
        List<Double> res = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while(!queue.isEmpty()) {
            int levelSize = queue.size();
            long sum = 0;
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                sum += node.val;

                if(node.left != null)
                    queue.offer(node.left);
                
                if(node.right != null) 
                    queue.offer(node.right);
            }

            double avg = (double) sum / levelSize;
            res.add(avg);
        }
        return res;
    }
}