class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> pos(n);

        for(int i = 0; i < n; i++) {
            pos[i] = i;
        }

        sort(pos.begin(), pos.end(), [&heights] (int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = names[pos[i]];
        }
        return ans;   
    }
};