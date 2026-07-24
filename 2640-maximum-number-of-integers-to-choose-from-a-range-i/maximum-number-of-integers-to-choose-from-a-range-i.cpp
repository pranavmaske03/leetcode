class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set;
        int sum = 0, res = 0;
        for(auto& val : banned) {
            if(val <= n) {
                set.insert(val);
            }
        }

        for(int i = 1; i <= n; i++) {
            if(sum > maxSum)
                break;
            if(set.find(i) == set.end() && (sum + i) <= maxSum) {
                sum += i;
                res++;
            }
        }
        return res;
    }
};