#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m, c;
vector<int> g[1001];
int cost[1001][1001];
int visit[1001];
int ans[1001];
int u, v;

void dfs(int root, int dist) {
	if (root == v){
		ans[root] = dist; return;
	} 
	for (int i = 0; i < g[root].size();i++){
		if (visit[g[root][i]]) continue;
		visit[g[root][i]] = 1;
		dfs(g[root][i], dist + cost[root][g[root][i]]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n-1;i++) {
		cin >> u >> v >> c;
		cost[u][v] = c;
		cost[v][u] = c;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while(m--) {
		fill(visit, visit + n + 1, 0);
		fill(ans, ans + n + 1, 0);
		cin >> u >> v;
		visit[u] = 1;
		dfs(u, 0);
		cout << ans[v] << endl;
	}
	return 0;
}