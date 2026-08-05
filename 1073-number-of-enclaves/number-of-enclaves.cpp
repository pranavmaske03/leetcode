class Solution {
public:
    int rows;
    int cols;

    bool dfs(int row, int col, vector<vector<int>>& grid, int& cells) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }
        if(grid[row][col] == 0) {
            return true;
        }
        cells++;
        grid[row][col] = 0;

        bool down = dfs(row + 1, col, grid, cells);
        bool up = dfs(row - 1, col, grid, cells);
        bool right = dfs(row, col + 1, grid, cells);
        bool left = dfs(row, col - 1, grid, cells);

        return down && up && right && left;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int totalCells = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    int cells = 0;
                    if(dfs(i, j, grid, cells)) 
                        totalCells += cells;
                }
            }
        }
        return totalCells;
    }
};