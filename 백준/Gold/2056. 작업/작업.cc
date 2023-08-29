#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int dp[10001];
int cost[10001];
int deg[10001];
vector<int> g[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;
    queue<int> q;

    cin >> n;

    for (int i=  1; i<=n;i++) {
        cin >> cost[i];
        dp[i] = cost[i];
        int t; cin >> t;
        if (!t) q.push(i);
        while (t--) {
            int x; cin >> x;
            g[x].push_back(i);
            deg[i]++;
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : g[cur]) {
            dp[nxt] = max(dp[nxt], dp[cur] + cost[nxt]);
            if (--deg[nxt] == 0)
                q.push(nxt);
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n);
    return 0;
}