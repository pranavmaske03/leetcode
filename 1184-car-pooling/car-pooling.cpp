class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int> check(1001, 0);

        for(auto& trip : trips) {
            check[trip[1]] += trip[0];
            check[trip[2]] -= trip[0];
        }
        int res = 0, cnt = 0;
        for(int& val : check) {
            cnt += val;
            res = max(res, cnt);
        }
        return res <= capacity;
    }
};