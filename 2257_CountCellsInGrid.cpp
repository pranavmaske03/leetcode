
/*
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {

        vector<vector<int>> grid(m,vector<int>(n,UNGUARDED));

        //assign the GUARD wherever they should be
        for(const auto& guard : guards)
        {
            grid[guard[0]][guard[1]] = GUARD;
        }

        //assign the walls wherever they should be
        for(const auto& wall : walls)
        {
            grid[wall[0]][wall[1]] = WALL;
        }


        //now mark all the guarded cells in the particular guard's range i.e. left,right,upwards,downwards
        for(const auto& guard : guards)
        {
            markGuarded(guard[0],guard[1],grid);
        }


        //count the ungaurded cells
        int count = 0;
        for(const auto& row : grid)
        {
            for(const auto& cell : row)
            {
                if(cell == UNGUARDED)
                {
                    count++;
                }
            }
        }


        return count;

    }

    void markGuarded(int row,int col,vector<vector<int>>& grid)
    {

        //travel upwards from guard pos
        for(int i = row-1;i >= 0;i--)
        {
            if(grid[i][col] == WALL || grid[i][col] == GUARD)
            {
                break;
            }

            grid[i][col] = GUARDED;
        }


        //travel downwards from guard pos
        for(int i = row + 1;i < grid.size();i++)
        {
            if(grid[i][col] == WALL || grid[i][col] == GUARD)
            {
                break;
            }

            grid[i][col] = GUARDED;
        }


        //travel leftside from guard pos
        for(int i = col - 1;i >= 0;i--)
        {
            if(grid[row][i] == WALL || grid[row][i] == GUARD)
            {
                break;
            }
            grid[row][i] = GUARDED;
        }

        
        //travel rightside from guard pos
        for(int i = col + 1;i < grid[row].size();i++)
        {
            if(grid[row][i] == WALL || grid[row][i] == GUARD)
            {
                break;
            }

            grid[row][i] = GUARDED;
        }

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