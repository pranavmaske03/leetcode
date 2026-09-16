/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    private void preorder(TreeNode root, StringBuilder sb) {
        if(root == null) {
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

    private TreeNode build(String[] tokens, int[] index) {
        String token = tokens[index[0]++];

        if(token.equals("#")) 
            return null;
        
        TreeNode root = new TreeNode(Integer.parseInt(token));

        root.left = build(tokens, index);
        root.right = build(tokens, index);

        return root;
    }
    public TreeNode deserialize(String data) {
        String[] tokens = data.split(",");
        int[] index = new int[1];

        return build(tokens, index);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));