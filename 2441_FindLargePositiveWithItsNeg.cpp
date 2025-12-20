#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution 
{
    public:
        int findMaxK(vector<int>& nums) 
        {
            unordered_set<int> st;
            int max_pos = -1;

            for (int num : nums) {
                if (num < 0) {
                    st.insert(num);
                }
            }
            for(int num : nums) {
                if(num > 0 && st.count(-num)) { 
                    max_pos = max(max_pos,num);
                }
            }
            return max_pos;
        }
};

int main()
{

    return 0;
}