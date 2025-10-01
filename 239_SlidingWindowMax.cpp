#include<iostream>
#include<vector>
#include <deque>
using namespace std;

class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            vector<int> res;
            deque<int> dq;

            for(int i = 0; i < nums.size(); i++)            
            {
                // remove first element if window has more elements than k
                if(!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }

                // remove smaller elements from the back
                while(!dq.empty() && nums[dq.back()] <= nums[i])
                {
                    dq.pop_back();
                }

                // push current index
                dq.push_back(i);

                // record max element
                if(i >= k-1) res.push_back(nums[dq.front()]);
            }
            return res;
        }
};

int main()
{

    return 0;
}