class Solution {
public:
    int rows;
    int cols;

    void dfs(int row, int col, vector<vector<char>>& board) {
        if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
            return;
        }

        board[row][col] = 'Z';
        dfs(row + 1, col, board);
        dfs(row - 1, col, board);
        dfs(row, col + 1, board);
        dfs(row, col - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int row = 0; row < rows; row++) {
            if(board[row][0] == 'O') {
                dfs(row, 0, board);
            }
            if(board[row][cols - 1] == 'O') {
                dfs(row, cols - 1, board);
            }
        }

        for(int col = 0; col < cols; col++) {
            if(board[0][col] == 'O') {
                dfs(0, col, board);
            }
            if(board[rows - 1][col] == 'O') {
                dfs(rows - 1, col, board);
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
};