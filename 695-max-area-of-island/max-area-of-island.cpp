class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return 0;
        if(grid[row][col] == 0 || visited[row][col])
            return 0;
      
        visited[row][col] = true;
        return 1 
            + dfs(row - 1, col, grid, visited)
            + dfs(row + 1, col, grid, visited)
            + dfs(row, col - 1, grid, visited)
            + dfs(row, col + 1, grid, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int currArea = dfs(i, j, grid, visited);
                    maxArea = max(currArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};