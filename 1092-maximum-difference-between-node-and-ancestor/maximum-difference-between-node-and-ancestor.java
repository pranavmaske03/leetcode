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
    public int maxDiff;

    public void DFS(TreeNode root, int minVal, int maxVal) {
        if(root == null)
            return;
        
        minVal = Math.min(minVal, root.val);
        maxVal = Math.max(maxVal, root.val);
        maxDiff = Math.max(maxDiff, (maxVal - minVal));

        DFS(root.left, minVal, maxVal);
        DFS(root.right, minVal, maxVal);
    }

    public int maxAncestorDiff(TreeNode root) {
        if(root == null)
            return 0;
        
        this.maxDiff = Integer.MIN_VALUE;
        DFS(root, root.val, root.val);
        return maxDiff;
    }
}