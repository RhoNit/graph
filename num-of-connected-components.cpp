// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> graph[N];
bool vis[N];

vector<vector<int>> conn_components;
vector<int> curr_conn_components;


void dfs(int vertex) {
	vis[vertex] = true;
	curr_conn_components.push_back(vertex);

	for(auto child : graph[vertex]) {
		if(vis[child]) continue;
		dfs(child);
	}
} 

int main() {
	int n, e;
	cin >> n >> e;

	for(int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	// int count = 0;

	for(int i = 1; i <= n; i++) {
		curr_conn_components.clear();
		if(vis[i]) continue;
		else {
			dfs(i);
			// count++;
			conn_components.push_back(curr_conn_components);
		}
	}

	// cout << count << endl;

	cout << conn_components.size() << endl;
}