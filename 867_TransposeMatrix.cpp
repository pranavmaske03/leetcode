#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) 
        {
            int row = matrix.size();
            int col = matrix[0].size();

            for(int i = 0; i < row-1; i++)
            {
                for(int j = i+1; j < col; j++)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            return matrix;
        }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    Solution obj;
    obj.transpose(matrix);;


    return 0;
}