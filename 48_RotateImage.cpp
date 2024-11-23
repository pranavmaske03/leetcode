#include<iostream>
#include<vector>

using namespace std;
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) 
        {
            for(int i = 0; i < matrix.size()-1; i++)
            {
                for(int j = i+1; j < matrix[i].size(); j++)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            for(int i = 0; i < matrix.size(); i++)
            {
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    obj.rotate(matrix);

    return 0;
}