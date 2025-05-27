#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int count = 0;

            int i = 0, j = col - 1;

            while (i < row && j >= 0) {
                if (grid[i][j] < 0) {
                    count += (row - i);
                    --j;
                } else {
                    ++i;
                }
            }

            return count;
        }
};

int main()
{
    vector<vector<int>> matrix = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    Solution obj;
    cout<<obj.countNegatives(matrix)<<"\n";

    return 0;
}