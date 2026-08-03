class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(row < 0 || row >= rows || col < 0 || col >= cols)
            return;
        if(grid[row][col] == '0' || visited[row][col]) 
            return;

        visited[row][col] = true;
        dfs(row + 1, col, grid, visited);
        dfs(row - 1, col, grid, visited);
        dfs(row, col - 1, grid, visited);
        dfs(row, col + 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == '1' && !visited[row][col]) {
                    islandCount++;
                    dfs(row, col, grid, visited);
                }
            }
        }
        return islandCount;
    }
};