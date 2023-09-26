// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void dfs(int vertex, vector<bool>& vis, vector<vector<int>>& adjList) {
        vis[vertex] = true;

        for(auto child: adjList[vertex]) {
            if(vis[child] == false) {
                dfs(child, vis, adjList);
            }
        }
    }    

    int findCircleNum(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size();
        int count = 0;

        vector<vector<int>> adjList(n);
        vector<bool> vis(n, false);

        for(int i = 0; i < adjMatrix.size(); i++) {
            for(int j = 0; j < adjMatrix[i].size(); j++) {
                if(adjMatrix[i][j] == 1 and i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < adjList.size(); i++) {
            if(vis[i] == false) {
                dfs(i, vis, adjList);
                ++count;
            }
        }

        return count;
    }
};