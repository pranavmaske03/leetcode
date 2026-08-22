class Solution {
    public int islandPerimeter(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int perimeter = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    if(i - 1 < 0 || grid[i - 1][j] == 0) {
                        perimeter += 1;
                    }
                    if(i + 1 >= rows || grid[i + 1][j] == 0) {
                        perimeter += 1;
                    }
                    if(j - 1 < 0 || grid[i][j - 1] == 0) {
                        perimeter += 1;
                    }
                    if(j + 1 >= cols || grid[i][j + 1] == 0) {
                        perimeter += 1;
                    }
                }
            }
        }
        return perimeter;
    }
}