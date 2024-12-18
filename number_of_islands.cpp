class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count_of_island = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    count_of_island++;
                    traverse(grid, i, j, n, m);
                }
            }
        }

        return count_of_island;
    }

    void traverse(vector<vector<char>> &grid, int i, int j, int n, int m) {
        if(i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == '1') {
            // mark the current processing cell as '0'
            // so that we don't have to visit that cell from the main() function
            grid[i][j] = '0';

            traverse(grid, i, j+1, n, m);
            traverse(grid, i, j-1, n, m);
            traverse(grid, i-1, j, n, m);
            traverse(grid, i+1, j, n, m);
        }

        return;
    }
};