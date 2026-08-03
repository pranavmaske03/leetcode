class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        if(grid[row][col] == 0 || visited[row][col])
            return;
      
        area++;
        visited[row][col] = true;

        dfs(row - 1, col, grid, visited, area);
        dfs(row + 1, col, grid, visited, area);
        dfs(row, col - 1, grid, visited, area);
        dfs(row, col + 1, grid, visited, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, visited, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};