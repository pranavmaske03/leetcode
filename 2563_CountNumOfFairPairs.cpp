#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) 
        {
            sort(nums.begin(), nums.end());  

            int n = nums.size();
            long long totalCount = 0;

            for(int i = 0; i < n; i++)
            {
                int left = -1, right = -1;
                int start = i + 1,end = n -1;

                while(start <= end) {
                    int mid = start + (end - start) /  2;

                    if(nums[mid] >= lower - nums[i]) {
                        left = mid;
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }

                start = i + 1,end = n-1;
                while(start <= end) {
                    int mid = start + (end - start) /  2;

                    if(nums[mid] <= upper - nums[i]) {
                        right = mid;
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                if(right != -1 && left != -1 && left <= right) {
                    totalCount += (right - left + 1);
                }
            }
            return totalCount;
        }
};


int main()
{

    return 0;
}