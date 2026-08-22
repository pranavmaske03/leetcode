class Solution {
    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        if(grid == null || grid.length == 0)
            return null;
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        dfs(grid, visited, r0, c0, grid[r0][c0], color);
        return grid;
    }

    public void dfs(int[][] grid, boolean[][] visited, int i, int j, int oldColor, int newColor) {
        if (i > grid.length - 1 || i < 0 || j > grid[0].length - 1 || j < 0 || grid[i][j] != oldColor || visited[i][j])
            return;

        visited[i][j] = true;
        boolean border = false;

        if(i == 0 || j == 0 || j == grid[0].length - 1 || i == grid.length - 1 || grid[i+1][j] != oldColor || grid[i-1][j] != oldColor || grid[i][j-1] != oldColor || grid[i][j+1] != oldColor)
            border = true;
        
        dfs(grid, visited, i+1, j, oldColor, newColor);
        dfs(grid, visited, i-1, j, oldColor, newColor);
        dfs(grid, visited, i, j+1, oldColor, newColor);
        dfs(grid, visited, i, j-1, oldColor, newColor);

        if(border) 
            grid[i][j] = newColor;            
    }
}