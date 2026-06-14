class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> idx;
        vector<int> ans(s.length());

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                idx.push_back(i);
            }
        }

        for (int i = 0, k = 0; i < s.length(); i++) {
            ans[i] = abs(i - idx[k]);
            if (k + 1 < idx.size() && i == idx[k]) {
                k++;
            }
        }

        for (int i = s.length() - 1, k = idx.size() - 1; i >= 0; i--) {
            ans[i] = min(ans[i], abs(i - idx[k]));
            if (k - 1 >= 0 && i == idx[k]) {
                k--;
            }
        }

        return ans;
    }
};