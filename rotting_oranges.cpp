class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int timer = 0;
        queue<pair<int, int>> q;

        int fresh_oranges = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) fresh_oranges++; 
            }
        }
        // case 3: When there is no fresh orange initially in the grid
        if(fresh_oranges == 0) return 0;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // bfs
        while(q.size() > 0) {
            int size = q.size();
            bool flag = false; // If a flag is not used, ususal for-loop iteration (without perfoming the rotting process) may lead to effect the timer count unnecessarily

            for(int i = 0; i < size; i++) {
                auto frnt = q.front();
                q.pop();

                // visit in every adjacent 4 directions w.r.t current cell
                for(auto elem: directions) {
                    int curr_x = frnt.first + elem[0];
                    int curr_y = frnt.second + elem[1];

                    if(curr_x >= 0 and curr_x < m and curr_y >= 0 and curr_y < n and grid[curr_x][curr_y] == 1) {
                        grid[curr_x][curr_y] = 2;
                        flag = true;
                        q.push({curr_x, curr_y});
                    }
                }
            }
            if(flag == true) timer++;
        }

        // case 2: When fresh oranges are yet there in the grid after performing dfs()
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return timer;
    }
};