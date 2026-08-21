class Solution {
    public int rows, cols;

    public void DFS(int i, int j, char[][] grid) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 'O') {
            return;
        }

        grid[i][j] = 'Z';
        DFS(i + 1, j, grid);
        DFS(i - 1, j, grid);
        DFS(i, j + 1, grid);
        DFS(i, j - 1, grid);
    }

    public void solve(char[][] board) {
        this.rows = board.length;
        this.cols = board[0].length;

        for(int i = 0; i < cols; i++) {
            if(board[0][i] == 'O') {
                DFS(0, i, board);
            }
            if(board[rows-1][i] == 'O') {
                DFS(rows-1, i, board);
            }
        }

        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') {
                DFS(i, 0, board);
            }
            if(board[i][cols-1] == 'O') {
                DFS(i, cols-1, board);
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}