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
    public TreeNode lca = null;
    public int maxDepth = 0;

    public int DFS(TreeNode root, int depth) {
        maxDepth = Math.max(maxDepth, depth);

        if(root == null)
            return depth;
        
        int left = DFS(root.left, depth + 1);
        int right = DFS(root.right, depth + 1);

        if(left == maxDepth && right == maxDepth)
            lca = root;
        
        return Math.max(left, right);
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        if(root == null)    
            return null;
        DFS(root, 0);
        return lca;
    }
}