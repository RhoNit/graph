// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        int m = adj.size(), n = adj[0].size();
        vector<int> visited(m, 0);
        vector<int> current_path(m, 0);
        
        for(int i = 0; i < m; i++) {
            if(!visited[i]) {
                bool res = dfs(adj, i, visited, current_path);
                if(res) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<int>> &adj, int node, vector<int> &visited, vector<int> &current_path) {
        visited[node] = 1;
        current_path[node] = 1;
        
        for(auto elem: adj[node]) {
            if(!visited[elem]) {
                bool res = dfs(adj, elem, visited, current_path);
                if(res) return true;
            }
            // if the elem is visited and is also included in the current_path 
            else if(visited[elem] and current_path[elem]) return true;
        }
        
        // backtrack the node's presence in the current_path vector
        current_path[node] = 0;
        
        return false;
    }
};