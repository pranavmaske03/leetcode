#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> luckyNumbers(vector<vector<int>>& matrix) 
        {
            vector<int> ans;

            int row = matrix.size();
            int col = matrix[0].size();

            for(int i = 0; i < row; i++)
            {
                int min = matrix[i][0];
                int k = 0;
                for(int j = 0; j < col; j++)
                {
                    if(min > matrix[i][j]) {
                        min = matrix[i][j];
                        k = j;
                    }
                }
                bool isLucky = true;
                for(int r = 0; r < row; r++)
                {
                    if(min < matrix[r][k]) {
                        isLucky = false;
                        break;
                    }
                }
                if(isLucky) {
                    ans.push_back(min);
                    break;
                }
            }
            return ans;
        }
};

int main()
{

    return 0;
}