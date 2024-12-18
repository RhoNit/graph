class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    traverse(grid, n, m, i, j, perimeter);
                    // since an island i.e. connected components is found return the result
                    return perimeter;
                }
            }
        }
        
        // when no island is found;
        return perimeter;
    }

    void traverse(vector<vector<int>> &grid, int n, int m, int curr_row, int curr_col, int &perimeter) {
        // following factors contributes to the perimeter:
        // if neighbouring cell is 0 i.e. grid[curr_row][curr_col] = 0
        // or at the edge of the grid i.e. curr_row > n or curr_row < 0
        // or curr_col > n or curr_col < 0
        if(curr_row >= n or curr_row < 0 or curr_col >= m or curr_col < 0 or grid[curr_row][curr_col] == 0) {
            perimeter++;
            return;
        }

        if(grid[curr_row][curr_col] == -1) return;
        
        // mark the already visited cell
        grid[curr_row][curr_col] = -1;
        

        traverse(grid, n, m, curr_row, curr_col-1, perimeter);
        traverse(grid, n, m, curr_row, curr_col+1, perimeter);
        traverse(grid, n, m, curr_row+1, curr_col, perimeter);
        traverse(grid, n, m, curr_row-1, curr_col, perimeter);
    }
};