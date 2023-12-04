#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int INF = 1e9;
int n, m;
int d[201][201];
int nxt[201][201];
int ans[201][201];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i<=n;i++) {
        fill(d[i], d[i] + n + 1, INF);
        d[i][i] = 0;
    }

    while (m--) {
        int u, v, c;

        cin >> u >> v >> c;
        d[u][v] = min(d[u][v], c);
        d[v][u] = min(d[v][u], c);
        nxt[u][v] = v;
        nxt[v][u] = u;
    }

    for (int k = 1; k <= n;k++) {
        for (int i = 1; i<=n;i++) {
            for (int j = 1; j<=n;j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<=n;j++) {
            if (i == j) continue;

            int st = i;
            vector<int> v;
            while (st != j) {
                v.push_back(st);
                st = nxt[st][j];
            }
            v.push_back(st);

            ans[i][j] = v[1];
        }
    }
    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<=n;j++) {
            if (i == j) cout << "- ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}