class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }
        if(grid[row][col] == 1 || visited[row][col]) {
            return true;
        }

        visited[row][col] = true;
        bool down = dfs(row + 1, col, grid, visited);
        bool up = dfs(row - 1, col, grid, visited);
        bool right = dfs(row, col + 1, grid, visited);
        bool left = dfs(row, col - 1, grid, visited);

        return down && up && right && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int closed = 0;
        bool isClosed = false;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == 0 && !visited[row][col]) {
                    if(dfs(row, col, grid, visited))
                        closed++;
                }
            }
        }
        return closed;
    }
};