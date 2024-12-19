// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int m = adj.size();
        int n = adj[0].size();
        vector<int> visited(m, 0);
        
        for(int i = 0; i < m; i++) {
            if(!visited[i]) {
                if(dfs(adj, m, n, i, visited, -1)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<int>>& adj, int m, int n, int node, vector<int> &visited, int parent) {
        visited[node] = 1;
        
        for(auto elem: adj[node]) {
            if(!visited[elem]) {
                if(dfs(adj, m, n, elem, visited, node)) return true;
            }
            else if(visited[elem] and elem != parent) return true;
        }
        
        return false;
    }
};