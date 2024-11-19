#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
        {
            int k = 0;
            bool *intersect = new bool[10001];

            for(int i = 0; i < nums1.size(); i++) 
            {
                intersect[nums1[i]] = true;
            }
            for(int i = 0; i < nums2.size(); i++)
            {
                if(intersect[nums2[i]] == true)
                {
                    nums1[k++] = nums2[i];
                    intersect[nums2[i]] = false;
                }
            }
            delete []intersect;
            return nums1;
        }
};

int main()
{
    vector<int> vect1{1,2,2,1};
    vector<int> vect2{2,2};

    Solution obj;
    obj.intersection(vect1,vect2);

    return 0;
}