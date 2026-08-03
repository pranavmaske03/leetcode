class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return 0;
        if(grid[row][col] == 0)
            return 0;
      
        grid[row][col] = 0;
        return 1 
            + dfs(row - 1, col, grid)
            + dfs(row + 1, col, grid)
            + dfs(row, col - 1, grid)
            + dfs(row, col + 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    int currArea = dfs(i, j, grid);
                    maxArea = max(currArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};