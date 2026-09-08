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
class Solution 
{
    public int maxDepth;
    public TreeNode lca;
    public int DFS(TreeNode root, int depth) 
    {
        maxDepth = Math.max(depth,maxDepth);
        if(root == null) return depth;

        int left = DFS(root.left, depth + 1);
        int right = DFS(root.right, depth + 1);

        if(left == maxDepth && right == maxDepth) {
            lca = root;
            System.out.println(lca.val);
        }
        return (left > right) ? left : right;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) 
    {
        if(root == null) return null;

        this.maxDepth = Integer.MIN_VALUE;
        this.lca = null;
        DFS(root, 0);
        return lca;
    }
}