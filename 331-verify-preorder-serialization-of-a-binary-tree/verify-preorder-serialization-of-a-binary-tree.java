class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] tokens = preorder.split(",");
        int slot = 1;

        for (int i = 0; i < tokens.length; i++) {
            if (tokens[i].equals("#"))
                slot--;
            else
                slot++;

            if (slot == 0 && i != tokens.length - 1)
                return false;
        }
        return slot == 0;
    }
}