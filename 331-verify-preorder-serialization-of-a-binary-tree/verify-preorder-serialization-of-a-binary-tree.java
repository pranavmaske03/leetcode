class Solution {
    public boolean isValidSerialization(String preorder) {
        int slot = 1;
        int n = preorder.length();

        for (int i = 0; i < n; i++) {
            if(preorder.charAt(i) == ',') {
                --slot;
                if(slot < 0)
                    return false;

                if(preorder.charAt(i - 1) != '#') 
                    slot += 2;
            }
        }
        slot = preorder.charAt(n - 1) != '#' ? slot + 1 : slot - 1;
        return slot == 0;
    }
}