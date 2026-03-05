#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int backtrack(int& n, int pos, vector<bool>& seen) {
            if(pos == 0) return 1;

            int ans = 0;
            for(int i = 1; i <= n; i++) {
                if(!seen[i] && (i % pos == 0 || pos % i == 0)) {
                    seen[i] = true;
                    ans += backtrack(n, pos - 1, seen);
                    seen[i] = false;
                }
            }
            return ans;
        }
        int countArrangement(int n) {
            vector<bool> seen(n+1, false);
            return backtrack(n, n, seen);
        }
};

int main() {
    Solution sol;
    int n = 2;
    cout << sol.countArrangement(n) << endl;
    return 0;
}