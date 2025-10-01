#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            int start = 0,end = numbers.size()-1;
            vector<int> res(2);
            while(start < end)
            {
                int currSum = numbers[start] + numbers[end];
                if(currSum == target) {
                    res[0] = start+1;
                    res[1] = end+1;
                    break;
                }

                if(currSum > target) {
                    end--;
                } else {
                    start++;
                }
            }
            return res;
        }
};

int main()
{

    return 0;
}