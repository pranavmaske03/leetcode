class Solution {
public:
    int rows;
    int cols;

    void dfs(int row, int col, vector<vector<int>>& grid, int& source, int& color) {
        if(row < 0 || row >= rows || col < 0 || col >= cols) 
            return;
        if(grid[row][col] != source) 
            return;
        
        grid[row][col] = color;
        dfs(row + 1, col, grid, source, color);
        dfs(row - 1, col, grid, source, color);
        dfs(row, col + 1, grid, source, color);
        dfs(row, col - 1, grid, source, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rows = image.size();
        cols = image[0].size();
        int source = image[sr][sc];

        if(source == color)
            return image;

        dfs(sr, sc, image, source, color);    
        return image;
    }
};