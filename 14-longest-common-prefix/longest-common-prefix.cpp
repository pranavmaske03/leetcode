class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string lsp = "";

        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() or strs[j][i] != strs[0][i]) {
                    return lsp;
                }
            }
            lsp += strs[0][i];
        }
        return lsp;
    }
};