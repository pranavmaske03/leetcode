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
    public TreeNode DFS(TreeNode root, int val, int depth, int currDepth) {
        if(root == null)
            return null;

        if(currDepth == depth - 1) {
            TreeNode left = new TreeNode(val);
            TreeNode right = new TreeNode(val);

            left.left = root.left;
            right.right = root.right;

            root.left = left;
            root.right = right;

            return root;
        }

        root.left = DFS(root.left, val, depth, currDepth + 1);
        root.right = DFS(root.right, val, depth, currDepth + 1);

        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(root == null)
            return null;

        if(depth == 1) {
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }

        return DFS(root, val, depth, 1);
    }
}