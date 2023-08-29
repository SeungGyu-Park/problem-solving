#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> g[32001];
int deg[32001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1 ; i<=n;i++) {
        if (deg[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        
        cout << cur << " ";
        for (int nxt : g[cur]) {
            if (--deg[nxt] == 0) pq.push(nxt);
        }
    }

    return 0;
}