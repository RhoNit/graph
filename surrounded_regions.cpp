class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // handle the border Os i.e. vertical ones
        // keeping the columns fixed
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') traverse(board, m, n, i, 0);
            if(board[i][n-1] == 'O') traverse(board, m, n, i, n-1);
        }

        // handle the border Os i.e. horizontal ones
        // keeping the rows fixed
        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') traverse(board, m, n, 0, i);
            if(board[m-1][i] == 'O') traverse(board, m, n, m-1, i);
        }

        // finally turn all boarder Os into `O`
        // and isolated Os into `X`
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X'; // isolated Os weren't handled or traversed, hence turn those into 'X' back
                else if(board[i][j] == 'B') board[i][j] = 'O'; // turn the border Os into 'O' back
            }
        }
    }

    void traverse(vector<vector<char>> &board, int m, int n, int row, int col) {
        if(row >= m or row < 0 or col >= n or col < 0 or board[row][col] != 'O') {
            return;
        }

        // mark the border Os as 'B'
        board[row][col] = 'B';

        traverse(board, m, n, row, col+1);
        traverse(board, m, n, row, col-1);
        traverse(board, m, n, row+1, col);
        traverse(board, m, n, row-1, col);
    }
};