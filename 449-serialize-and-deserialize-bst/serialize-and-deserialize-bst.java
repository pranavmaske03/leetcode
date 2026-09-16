/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 String s = String.valueOf(n);
 */
public class Codec {

    private void preorder(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append("#,");
            return;
        }
        sb.append(root.val).append(",");

        preorder(root.left, sb);
        preorder(root.right, sb);
    }
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        preorder(root, sb);
        return sb.toString();
    }

    private int idx;
    private TreeNode build(String[] tokens) {
        String token = tokens[idx++];

        if(token.equals("#")) 
            return null;
        
        TreeNode root = new TreeNode(Integer.parseInt(token));

        root.left = build(tokens);
        root.right = build(tokens);

        return root;
    }

    public TreeNode deserialize(String data) {
        String[] tokens = data.split(",");
        this.idx = 0;
        return build(tokens);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;