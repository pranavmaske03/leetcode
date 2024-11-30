#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
        {
            int count = 0;
            vector<int> result(101,-1);
            vector<int> clone = nums;
        	std::sort(nums.begin(),nums.end()); // Sorting the vector in ascending order

            for(int i = 0; i < nums.size(); i++)
            {
                if(result[nums[i]] == -1)
                {
                    result[nums[i]] = count++;
                }
                else
                {
                    count++;
                }
            }
            for(int i = 0; i < nums.size(); i++)
            {
                nums[i] = result[clone[i]];
            }
            return nums;
        }
};
int main()
{
    vector<int> vect{8,1,2,2,3};
    Solution obj;

    obj.smallerNumbersThanCurrent(vect);
    return 0;
}