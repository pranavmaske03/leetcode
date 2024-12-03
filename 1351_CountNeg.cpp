#include<iostream>
#include<vector>
 
using namespace std;

class Solution 
{
    public:
        int countNegatives(vector<vector<int>>& grid) 
        {
            int count = 0;
            for(int i = grid.size()-1; i >= 0; i--)
            {
                for(int j = grid[i].size()-1; j >= 0; j--)
                {
                    if(grid[i][j] < 0)
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
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