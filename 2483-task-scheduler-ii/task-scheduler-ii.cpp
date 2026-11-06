class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        unordered_map<int, long long> mp;
        long long res = 0;

        for(int i = 0; i < tasks.size(); i++) {

            if(mp.count(tasks[i])) {
                res = max(res, mp[tasks[i]] + space + 1);
            }

            mp[tasks[i]] = res;
            res++;
        }

        return res;
    }
};