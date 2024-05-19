#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
int deg[32001];
vector<int> adj[32001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for (int i = 1; i<=n;i++){
        if (deg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    return 0;
}