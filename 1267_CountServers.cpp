#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:
        int countServers(vector<vector<int>>& grid) 
        {
            vector<int> rowServer(size(grid[0]), 0), columnServer(size(grid), 0);   
            int connectedServers = 0;

            for(int row = 0; row < grid.size(); row++)
            {
                for(int col = 0; col < grid[row].size(); col++)
                {
                    if(grid[row][col]){
                        rowServer[col]++;
                        columnServer[row]++;
                    }   
                }
            }
            for (int row = 0; row < size(grid); ++row)
            {
                for (int col = 0; col < size(grid[0]); ++col)
                {
                    if (grid[row][col])
                    {
                        connectedServers += rowServer[col] > 1 || columnServer[row] > 1;
                        cout<<connectedServers<<endl;
                    }
                }
            }
            return connectedServers;
        }
};

int main()
{
    vector<vector<int>> grid = {{1,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    Solution obj;
    cout<<obj.countServers(grid);

    return 0;
}