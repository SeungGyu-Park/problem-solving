#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> g[100'001];
int vis[100'001];

void dfs(int root) {
    vis[root] = 1;
    for (int &nxt_child : g[root]) {
        if (vis[nxt_child]) continue;
        dfs(nxt_child);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    
    cin >> n >> m;
    int tmp = m;
    while (tmp--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i<=n;i++) {
        if (vis[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << cnt-1 + (m + cnt - 1) - (n - 1);
    return 0;
}