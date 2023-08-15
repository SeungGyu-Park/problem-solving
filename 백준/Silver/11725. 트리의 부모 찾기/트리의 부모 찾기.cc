#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
vector<int> g[100001];
int p[100001];

void dfs(int parent) {
	for (int child : g[parent]) {
		if (p[parent] == child) continue;
		p[child] = parent;
		dfs(child);
	}
}


void bfs(int parent) {
	queue<int> q;
	q.push(parent);
	while(!q.empty()) {
		int root = q.front();
		q.pop();
		for (int c : g[root]) {
			if (p[root] == c) continue;
			p[c] = root;
			q.push(c);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0 ; i<n-1;i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	// dfs(1);
	bfs(1);
	for (int i = 2; i<=n;i++)
		cout << p[i] << endl;
	return 0;
}