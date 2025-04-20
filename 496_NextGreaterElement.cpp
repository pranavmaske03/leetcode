#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution 
{
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
            unordered_map<int,int> map;
            vector<int> result;
            stack<int> st;

            for(int i = nums2.size()-1; i >= 0; i--) {
                
                while(!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }

                if(!st.empty()) map[nums2[i]] = st.top();
                else map[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            for(int num : nums1) {
                result.push_back(map[num]);
            }
            return result;
        }
};

int main()
{
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    Solution obj;

    vector<int> res = obj.nextGreaterElement(nums1,nums2);
    for(int i : res) cout<<i<<"\t";
    cout<<"\n";
    return 0;
}