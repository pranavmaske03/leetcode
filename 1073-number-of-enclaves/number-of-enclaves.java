class Solution {
    public int rows, cols;

    public void DFS(int i, int j, int[][] grid) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1)
            return;
        
        grid[i][j] = 0;
        DFS(i + 1, j, grid);
        DFS(i - 1, j, grid);
        DFS(i, j + 1, grid);
        DFS(i, j - 1, grid);
    }

    public int numEnclaves(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;

        for(int i = 0; i < cols; i++) {
            if(grid[0][i] == 1)
                DFS(0, i, grid);
            if(grid[rows - 1][i] == 1) 
                DFS(rows - 1, i, grid);
        }

        for(int i = 0; i < rows; i++) {
            if(grid[i][0] == 1) 
                DFS(i, 0, grid);
            if(grid[i][cols - 1] == 1)
                DFS(i, cols - 1, grid);
        }

        int landCells = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) 
                    landCells++;
            }
        }
        return landCells;
    }
}