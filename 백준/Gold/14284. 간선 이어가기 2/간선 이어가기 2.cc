#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m, s, t;
int d[5001];
vector<pair<int, int>> g[5001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    fill(d, d + n+1, 1e9);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }

    cin >> s >> t;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int c, v, nc, nv;

        tie(c, v) = pq.top(); pq.pop();

        if (d[v] != c) continue;
        for (auto e : g[v]) {
            tie(nc, nv) = e;
            if (d[v] + nc >= d[nv]) continue;
            d[nv] = d[v] + nc;
            pq.push({d[nv], nv});
        }
    }

    cout << d[t];
    return 0;
}