class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    traverse(grid, m, n, i, j, area);
                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }

    void traverse(vector<vector<int>> &grid, int m, int n, int row, int col, int &area) {
        // edge case: row/col is beyond the grid
        if(row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != 1) {
            return;
        }

        area += 1;

        // mark the current cell as visited to prevent the future traversing
        grid[row][col] = 0;

        traverse(grid, m, n, row, col+1, area);
        traverse(grid, m, n, row, col-1, area);
        traverse(grid, m, n, row+1, col, area);
        traverse(grid, m, n, row-1, col, area);
    }
};