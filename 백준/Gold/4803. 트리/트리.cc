#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
vector<int> g[501];
int visit[501];
int isTree;
int ans;

void dfs(int root, int child) {
	for (int next_child : g[root]) {
		if (next_child == child) {
			continue;
		}
		if (visit[next_child]) {
			isTree =0;
		}
		else {
			visit[next_child] = 1;
			dfs(next_child, root);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int tc = 0;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		
		// init
		for (int i = 0; i<=n;i++){
			g[i].clear();
			visit[i] = 0;
		}
		ans = 0;
		for (int i = 0; i<m;i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		for (int i = 1; i<=n;i++){
			if (visit[i]) continue;
			visit[i] = 1;
			isTree = 1;
			dfs(i, -1);
			ans += isTree;
		}
		cout << "Case " << ++tc << ": ";
		if (ans == 0)
			cout << "No trees." << endl;
		else if (ans == 1)
			cout << "There is one tree." << endl;
		else cout << "A forest of " << ans << " trees." << endl;
	}
	return 0;
}