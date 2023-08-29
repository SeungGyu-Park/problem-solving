#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

ll dp[10001];
ll cost[10001];
ll deg[10001];
vector<int> g[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;

    cin >> n;

    for (int i=  1; i<=n;i++) {
        cin >> cost[i];
        dp[i] = cost[i];
        int t; cin >> t;
        while (t--) {
            int x; cin >> x;
            g[x].push_back(i);
            deg[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i<=n;i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : g[cur]) {
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + cost[nxt]);
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
    return 0;
}