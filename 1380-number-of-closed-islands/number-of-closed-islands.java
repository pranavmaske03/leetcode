class Solution {
    public int rows, cols;

    public boolean DFS(int i, int j, int[][] grid, boolean[][] visited) {
        if(i < 0 || i >= rows || j < 0 || j >= cols) 
            return false;

        if(grid[i][j] == 1 || visited[i][j]) 
            return true;

        visited[i][j] = true;

        boolean DOWN = DFS(i + 1, j, grid, visited);
        boolean UP = DFS(i - 1, j, grid, visited);
        boolean RIGHT = DFS(i, j + 1, grid, visited);
        boolean LEFT = DFS(i, j - 1, grid, visited);

        return DOWN && UP && RIGHT && LEFT;
    }

    public int closedIsland(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        int isLandCount = 0;
        boolean[][] visited = new boolean[rows][cols];

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 0 && visited[i][j] == false) {
                    if(DFS(i, j, grid, visited)) {
                        isLandCount++;
                    }
                }
            }
        }
        return isLandCount;
    }
}