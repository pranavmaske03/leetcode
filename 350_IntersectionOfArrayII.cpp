#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
        {
            unordered_map<int,int>map;
            vector<int> result;

            for(int num : nums1) {
                map[num]++;
            }
            for(int num : nums2) {
                if(map[num] > 0) {
                    result.push_back(num);
                    map[num]--;
                }
            }
            return result;
        }
};

int main()
{
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    Solution obj;
    obj.intersect(nums1,nums2);

    return 0;
}