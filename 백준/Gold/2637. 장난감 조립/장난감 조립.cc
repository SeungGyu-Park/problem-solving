#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<pair<int, int>> g[101];
int dp[101];
int deg[101];
int middles[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        middles[u] = 1;
        g[u].push_back({v, c});
        deg[v]++;
    }
    queue<int> q;
    q.push(n);
    dp[n] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (pair<int, int> e : g[cur]) {
            int nxt, cost;
            tie(nxt, cost) = e;

            dp[nxt] += cost * dp[cur];
            if (--deg[nxt] == 0) q.push(nxt);
        }
    }
    for (int i = 1; i<=n;i++) {
        if (middles[i]) continue;
        cout << i << " " << dp[i] << endl;
    }
    return 0;
}