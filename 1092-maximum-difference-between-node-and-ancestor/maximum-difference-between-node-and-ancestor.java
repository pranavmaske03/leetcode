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
    public int DFS(TreeNode root, int minVal, int maxVal) {
        if(root == null)
            return 0;
        
        minVal = Math.min(minVal, root.val);
        maxVal = Math.max(maxVal, root.val);
    
        int currDiff = maxVal - minVal;
        int leftDiff = DFS(root.left, minVal, maxVal);
        int rightDiff = DFS(root.right, minVal, maxVal);

        return Math.max(currDiff, Math.max(leftDiff, rightDiff));
    }

    public int maxAncestorDiff(TreeNode root) {
        if(root == null)
            return 0;
        return DFS(root, root.val, root.val);
    }
}