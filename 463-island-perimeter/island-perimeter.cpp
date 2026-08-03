class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
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
};