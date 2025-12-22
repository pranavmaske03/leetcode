#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<string> summaryRanges(vector<int>& nums) 
        {
            vector<string> result;
            int n = nums.size();
            if (n == 0) return result;

            int start = nums[0];

            for (int i = 0; i < n; i++) {
                if (i == n - 1 || nums[i] + 1 != nums[i + 1]) {
                    int end = nums[i];

                    if (start == end) {
                        result.push_back(to_string(start));
                    } else {
                        result.push_back(to_string(start) + "->" + to_string(end));
                    }
                    if (i + 1 < n) {
                        start = nums[i + 1];
                    }
                }
            }
            return result;
        }
};


int main()
{

    return 0;
}