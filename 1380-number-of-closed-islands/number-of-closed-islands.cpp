class Solution {
public:
    int rows;
    int cols;

    bool dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }
        if (grid[row][col] == 1) {
            return true;
        }

        grid[row][col] = 1;

        bool down = dfs(row + 1, col, grid);
        bool up = dfs(row - 1, col, grid);
        bool right = dfs(row, col + 1, grid);
        bool left = dfs(row, col - 1, grid);

        return down && up && right && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int closed = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    if (dfs(row, col, grid)) {
                        closed++;
                    }
                }
            }
        }
        return closed;
    }
};