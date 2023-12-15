#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int r[10001];
int vis[10001];
pair<int, int> cost[10001];
int n, m, k;

int find(int x) {
    if (x == r[x]) return x;
    return r[x] = find(r[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) r[b] = a;
    else r[a] = b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i = 1; i <= n;i++) {
        int c; cin >> c;
        
        r[i] = i;
        cost[i] = {c, i};
    }

    
    sort(cost+1, cost + n+1);
    for (int i = 0; i < m;i++) {
        int v, w;

        cin >> v >> w;
        if (find(v) == find(w)) continue;
        uni(v, w);
    }

    int ans = 0;
    for (int i = 1; i<= n;i++) {
        int cur, c;
        tie(c, cur) = cost[i];
        
        int root = find(cur);
        if (vis[root]) continue;
        vis[root] = 1;
        ans += c;
    }
    if (ans <= k) cout << ans;
    else cout << "Oh no";
    return 0;
}