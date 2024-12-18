class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjList(n); // we will store `node/vertex` as first elem and a `reverse_counter` as second elem of the pair
        vector<int> visited(n);

        for(auto elem: connections) {
            int a = elem[0];
            int b = elem[1];

            adjList[a].push_back({b, 1});  // since the forward-directed edges are needed to be reversed, counter=1 is added as a second elem of the pair
            adjList[b].push_back({a, 0});  // since this is backward-directed edge and isn't needed to be reversed, counter=0 is added as a second elem of the pair
        }
        int src = 0;
        int reverse_cnt = 0;
        solve_using_dfs(src, adjList, visited, reverse_cnt);

        return reverse_cnt;
    }

    void solve_using_dfs(int src, vector<vector<pair<int, int>>> &adjList, vector<int> &visited, int &reverse_cnt) {
        visited[src] = 1;

        for(auto elem: adjList[src]) {
            auto node = elem.first;
            auto counter = elem.second;

            if(!visited[node]) {
                reverse_cnt += counter;
                solve_using_dfs(node, adjList, visited, reverse_cnt);
            }
        }
    }
};