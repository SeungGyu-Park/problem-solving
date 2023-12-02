#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int v, e, k;
vector<pair<int, int>> adj[20005];
int d[20005];
const int INF = 1e9;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> v >> e >> k;
    fill(d, d + v + 1, INF);
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    d[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[k], k});
    while (!pq.empty()) {
        int cur_w = pq.top().first;
        int cur_v = pq.top().second;
        pq.pop();
        for (auto nxt : adj[cur_v]) {
            int cost = nxt.first;
            int nxt_v = nxt.second;
            if (d[nxt_v] > cur_w + cost) {
                d[nxt_v] = cur_w + cost;
                pq.push({d[nxt_v], nxt_v});
            }
        }
    }
    for (int i = 1; i<=v;i++){
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << endl;
    }
    return 0;
}