class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return 1;
        }
        if (grid[row][col] == 0) {
            return 1;
        }
        if (visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;
        int perimeter = 0;

        perimeter += dfs(row - 1, col, grid, visited);
        perimeter += dfs(row + 1, col, grid, visited);
        perimeter += dfs(row, col - 1, grid, visited);
        perimeter += dfs(row, col + 1, grid, visited);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    return dfs(row, col, grid, visited);
                }
            }
        }

        return 0;
    }
};