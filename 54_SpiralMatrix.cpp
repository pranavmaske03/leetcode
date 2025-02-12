#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) 
        {
            int top = 0,left = 0;
            int right = matrix[0].size()-1,bottom = matrix.size()-1;
            vector<int> result;

            while(top <= bottom && left <= right) 
            {
                for(int i = left; i <= right; i++) 
                {
                    result.push_back(matrix[top][i]);
                }
                top++;
                for(int i = top; i <= bottom; i++)
                {
                    result.push_back(matrix[i][right]);
                }
                right--;

                if(top <= bottom) 
                {
                    for(int i = right; i >= left; i--) 
                    {
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                }

                if(left <= right)
                {
                    for(int i = bottom; i >= top; i--)
                    {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            for(auto i : result) cout<<i<<" ";
            return result;
        }
};
int main() {

    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    obj.spiralOrder(mat);


    return 0;
}