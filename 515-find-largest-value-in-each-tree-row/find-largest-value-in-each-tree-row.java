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
    public void DFS(TreeNode root, int level, List<Integer> res) {
        if(root == null)
            return;
        
        if(level == res.size()) {
            res.add(root.val);
        } else {
            res.set(level, Math.max(res.get(level), root.val));
        }

        DFS(root.left, level+1, res);
        DFS(root.right, level+1, res);
    }

    public List<Integer> largestValues(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        
        List<Integer> result = new ArrayList<>();
        DFS(root, 0, result);
        return result;
    }
}