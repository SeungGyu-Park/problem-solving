#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, r;
int cost[101];
int d[101][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m >> r;
    for (int i = 1; i<=n;i++){
        fill(d[i], d[i] + 1 +n, INF);
        d[i][i] = 0;
    }

    for (int i = 1; i<=n;i++) cin >> cost[i];

    while (r--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    for (int k = 1; k <=n;k++){
        for (int i =1; i <=n;i++){
            for (int j = 1; j<=n;j++){
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int ans = -1;
    for (int i =1; i<=n;i++){
        int sum = cost[i];
        for (int j = 1; j<=n;j++){
            if (i == j || d[i][j] == INF) continue;
            if (d[i][j] > m) continue;
            sum += cost[j];
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}