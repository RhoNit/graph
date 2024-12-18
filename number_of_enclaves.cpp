class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // find out the vertical bordered land cells
        // keeping the columns constant
        for(int i = 0; i < m; i++) {
            if(grid[i][0]) traverse(grid, m, n, i, 0);
            if(grid[i][n-1]) traverse(grid, m, n, i, n-1);
        }

        // find out the horizontal bordered land cells
        // keeping the rows constant
        for(int i = 0; i < n; i++) {
            if(grid[0][i]) traverse(grid, m, n, 0, i);
            if(grid[m-1][i]) traverse(grid, m, n, m-1, i);
        }

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }

    void traverse(vector<vector<int>> &grid, int m, int n, int row, int col) {
        // edge case
        if(row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != 1) {
            return;
        }

        // mark the visited ones as 0 again or we can put any number here execept 1
        grid[row][col] = 0;

        traverse(grid, m, n, row, col+1);
        traverse(grid, m, n, row, col-1);
        traverse(grid, m, n, row+1, col);
        traverse(grid, m, n, row-1, col);
    }
};