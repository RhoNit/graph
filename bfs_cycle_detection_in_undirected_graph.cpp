// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int m = adj.size();
        int n = adj[0].size();
        vector<int> visited(m, 0);
        vector<int> parent(m, -1);
        
        for(int i = 0; i < m; i++) {
            if(!visited[i]) {
                bool ans = bfs(adj, i, visited, parent);
                if(ans == true) return true;
            }
        }
        
        return false;
    }
    
    bool bfs(vector<vector<int>>& adj, int node, vector<int> &visited, vector<int> &parent) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        
        while(q.size() > 0) {
            auto frnt = q.front();
            q.pop();
            
            for(auto elem: adj[frnt]) {
                if(!visited[elem]) {
                    q.push(elem);
                    visited[elem] = 1;
                    parent[elem] = frnt;
                }
                else if(visited[elem] and elem != parent[frnt]) return true;
            }
        }        
        return false;
    }
};