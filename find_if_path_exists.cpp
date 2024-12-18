class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n);

        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        solve_bfs(adjList, visited, source);

        return (visited[destination] == 1) ? true : false;
    }

    void solve_bfs(vector<vector<int>> &adjList, vector<int> &visited, int src) {
        queue<int> q;
        q.push(src);
        visited[src] = 1;

        while(q.size() > 0) {
            auto f = q.front();
            q.pop();

            for(auto elem: adjList[f]) {
                if(!visited[elem]) {
                    visited[elem] = 1;
                    q.push(elem);
                }
            }
        }
    }

    // void solve_dfs(vector<vector<int>> &adjList, vector<int> &visited, int src) {
    //     visited[src] = 1;

    //     for(auto elem: adjList[src]) {
    //         if(!visited[elem]) {
    //             // visited[elem] = 1;
    //             solve_dfs(adjList, visited, elem);
    //         }
    //     }
    // }
};