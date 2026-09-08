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
class Pair {
    TreeNode node;
    long idx;

    Pair(TreeNode node, long idx) {
        this.node = node;
        this.idx = idx;
    }
}

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));
        int res = 1;

        while(!queue.isEmpty()) {
            int size = queue.size();

            long start = queue.peek().idx;
            long end = start;

            for(int i = 0; i < size; i++) {
                Pair pair = queue.poll();

                TreeNode node = pair.node;
                long idx = pair.idx;
                end = idx;

                if(node.left != null) {
                    queue.offer(new Pair(node.left, 2 * idx + 1));
                }

                if(node.right != null) {
                    queue.offer(new Pair(node.right, 2 * idx + 2));
                }
            }
            res = Math.max(res, (int)(end - start + 1));
        }
        return res;
    }
}