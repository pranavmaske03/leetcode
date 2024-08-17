#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            int row = matrix.size();
            int col = matrix[0].size();
            bool flag = false;

            for(int i = 0,m = row-1; i < row; i++,m--)
            {
                for(int j = 0,n = col-1; j < col; j++,n--)
                {
                    if(matrix[i][j] == target)
                    {
                        flag = true;
                        break;
                    }
                    if(matrix[m][n] == target)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag == true) break;
            }
            return flag;
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