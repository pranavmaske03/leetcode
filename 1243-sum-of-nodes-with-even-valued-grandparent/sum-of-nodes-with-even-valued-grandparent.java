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
    int sum = 0;
    public void DFS(TreeNode curr, TreeNode parent, TreeNode grandParent) {
        if(curr == null)
            return;
        
        if(grandParent != null && grandParent.val % 2 == 0) {
            sum += curr.val;
        }

        DFS(curr.left, curr, parent);
        DFS(curr.right, curr, parent);
    }

    public int sumEvenGrandparent(TreeNode root) {
        if(root == null)
            return 0;

        DFS(root, null, null);
        return sum;
    }
}