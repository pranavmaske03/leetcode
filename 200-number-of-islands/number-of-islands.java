class Solution {
    public int rows, cols;

    public void DFS(int i, int j, char[][] grid, boolean[][] visited) {
        if(i < 0 || i >= rows || j < 0 || j >= cols) 
            return;

        if(grid[i][j] == '0' || visited[i][j] == true) 
            return;
        
        visited[i][j] = true;

        DFS(i + 1, j, grid, visited);
        DFS(i - 1, j, grid, visited);
        DFS(i, j + 1, grid, visited);
        DFS(i, j - 1, grid, visited);
    }

    public int numIslands(char[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        int landCount = 0;

        boolean[][] visited = new boolean[rows][cols];
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && visited[i][j] == false) {
                    DFS(i, j, grid, visited);
                    landCount++;
                }
            }
        }
        return landCount;
    }
}