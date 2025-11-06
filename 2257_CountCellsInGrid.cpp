
/*
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
    public:

        const char UNGUARDED = 'U';
        const char GUARD = 'G';
        const char SEEN = 'S';
        const char WALL = 'W';

        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
        {
            vector<vector<char>> grid(m, vector<char>(n, UNGUARDED));
            int count = 0;

            // mark walls
            for(auto &wall : walls) {
                grid[wall[0]][wall[1]] = WALL;
            }

            // mark guards
            for(auto &guard : guards) {
                grid[guard[0]][guard[1]] = GUARD;
            }

            // mark seen cells in all 4 directions
            for(int i = 0; i < guards.size(); i++)
            {
                int r = guards[i][0];
                int c = guards[i][1];

                // travel right
                for(int k = c + 1; k < n && grid[r][k] != WALL && grid[r][k] != GUARD; k++)   grid[r][k] = SEEN;
                
                // travel left
                for(int k = c - 1; k >= 0 && grid[r][k] != WALL && grid[r][k] != GUARD; k--)  grid[r][k] = SEEN;

                // travel down
                for(int k = r + 1; k < m && grid[k][c] != WALL && grid[k][c] != GUARD; k++)   grid[k][c] = SEEN;

                // travel up
                for(int k = r - 1; k >= 0 && grid[k][c] != WALL && grid[k][c] != GUARD; k--)  grid[k][c] = SEEN;
            }

            // count unguarded cells
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == UNGUARDED) count++;
                }
            }

            return count;
        }
};


int main()
{

    Solution s;

    vector<vector<int>> gaurds = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};

    int m = 4,n = 6;
    
    cout<<s.countUnguarded(m,n,gaurds,walls);

    return 0;
}