#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int INF = 1e9;
int n, m, st, en;
int d[1001];
vector<pair<int, int>> g[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    fill(d, d + n + 1, INF);
    while (m--) {
        int u, v, c;

        cin >> u >> v >> c;
        g[u].push_back({c, v});
    }

    cin >> st >> en;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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

    cout << d[en];
    return 0;   
}