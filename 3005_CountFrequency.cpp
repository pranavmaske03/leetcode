#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
        int maxFrequencyElements(vector<int>& nums) 
        {
            vector<int> count_freq(101,0);

            for(auto i : nums)
            {
                count_freq[i]++;
            }
            int max = 0,count = 0;
            for(auto val : count_freq)
            {
                if(max < val)
                {
                    max = val;
                    count = 0;
                }
                if(max == val) count++;
            }
            return count * max;
        }
};
int main()
{


    return 0;
}