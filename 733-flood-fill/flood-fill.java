class Solution {
    public int rows, cols;

    public void DFS(int i, int j, int[][] grid, int oldColor, int color) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != oldColor) 
            return;
        
        grid[i][j] = color;
        DFS(i + 1, j, grid, oldColor, color);
        DFS(i - 1, j, grid, oldColor, color);
        DFS(i, j + 1, grid, oldColor, color);
        DFS(i, j - 1, grid, oldColor, color);
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        this.rows = image.length;
        this.cols = image[0].length;
        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        DFS(sr, sc, image, oldColor, color);
        return image;
    }
}