class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        if(n == 1) {
            int ans = 0;
            for(auto& row : units) {
                ans += row[0];
            }
            return ans;
        }
        
        long long sum = 0;
        int first_min = INT_MAX;
        int sec_min = INT_MAX;

        for(auto& row : units) {
            sort(row.begin(), row.end());

            int first = row[0];
            int second = row[1];

            first_min = min(first_min, first);
            sec_min = min(sec_min, second);
            sum += second;
        }
        return sum - sec_min + first_min;
    }
};