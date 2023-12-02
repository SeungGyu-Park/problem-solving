#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int INF = 1e9;
int n, m, e;
int d[1001];
vector<pair<int, int>> g[1001];

int dik(int st, int en) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    fill(d, d + n + 1, INF);
    d[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        int c, v, nc, nv;
        tie(c, v) = pq.top(); pq.pop();
        if (d[v] != c) continue;
        for (auto e : g[v]) {
            tie(nc, nv) = e;
            nc += c;
            if (d[nv] > nc) {
                d[nv] = nc;
                pq.push({d[nv], nv});
            }
        }
    }
    return d[en];
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m >> e;

    while (m--) {
        int u, v, c;

        cin >> u >> v >> c;
        g[u].push_back({c, v});
    }

    int ans = -1;
    for (int i =1; i<=n;i++) {

        ans = max(ans, dik(i, e) + dik(e, i));
    }
    cout <<ans;
    return 0;   
}