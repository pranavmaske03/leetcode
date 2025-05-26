#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int rows = matrix.size();
            int cols = matrix[0].size();

            int left = 0;
            int right = rows * cols -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                int mid_value = matrix[mid/cols][mid%cols];

                if(mid_value == target) {
                    return true;
                } else if(mid_value > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return false;
        }
};

int main()
{   
    // syntax to create 2d array 
    vector<vector<int>> arr{{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    Solution obj;
    bool bRet = obj.searchMatrix(arr,16);
    if(bRet == true)
    {
        cout<<"Present\n";
    }
    else
    {
        cout<<"Not present\n";
    }

    return 0;
}