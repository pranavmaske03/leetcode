class Solution {
    public int rows, cols;
    
    public int DFS(int i, int j, int[][] grid, boolean[][] visited) {
        if(i < 0 || i >= rows || j < 0 || j >= cols) 
            return 0;

        if(grid[i][j] == 0 || visited[i][j])
            return 0;
        
        visited[i][j] = true;
        
        return 1 
            + DFS(i + 1, j, grid, visited)
            + DFS(i - 1, j, grid, visited)
            + DFS(i, j + 1, grid, visited)
            + DFS(i, j - 1, grid, visited);
    }

    public int maxAreaOfIsland(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;

        boolean[][] visited = new boolean[rows][cols];
        int maxArea = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int area = DFS(i, j, grid, visited);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
}