#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int findNumbers(vector<int>& nums) {
            int evenNum = 0;

            for(auto val : nums) {
                string strVal = to_string(val);
                if(!(strVal.length() % 2)) {
                    evenNum++;
                }
            }
            return evenNum;
        }
};

int main() 
{
    vector<int> vec{555,901,482,1771};
    Solution obj;

    cout<<obj.findNumbers(vec);
}