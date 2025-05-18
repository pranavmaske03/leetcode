#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int num;
    int index;
} Number;

class Solution 
{
    public:
        static bool compare(const Number &a, const Number &b) {
            return a.num < b.num; // ascending order
            // return a.num > b.num; // use this for descending order
        }

        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<Number> numbers(nums.size());
            vector<int> ret;

            for(int i = 0; i < nums.size(); i++) {
                numbers[i].num = nums[i];
                numbers[i].index = i;
            }
            // sorting
            sort(numbers.begin(), numbers.end(), compare);

            int left = 0;
            int right = nums.size() -1;

            while(left < right) {
                int currSum = numbers[left].num + numbers[right].num;
                if(currSum == target) {
                    ret.push_back(numbers[left].index);
                    ret.push_back(numbers[right].index);
                    return ret;
                } else if(currSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
            return ret;
        }
};

int main()
{
    vector<int> nums{2,7,11,15};
    int target = 9;

    Solution obj;
    vector<int> ret = obj.twoSum(nums,target);
    for(auto val : ret) {
        cout<<val<<"\t";
    }
    cout<<"\n";

    return 0;
}