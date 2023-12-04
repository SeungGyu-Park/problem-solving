#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int d[21][21];
bool b[21][21];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 1 ;i<=n;i++)
        for (int j = 1; j<=n;j++)
            cin >> d[i][j];

    for (int k = 1; k<=n;k++) {
        for (int i = 1; i<=n;i++) {
            for (int j = 1; j<=n;j++) {
                if (i == k || j == k) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    cout << -1; return 0;
                }
                if (d[i][j] == d[i][k] + d[k][j])
                    b[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i<=n;i++)
        for (int j = i + 1; j<=n;j++)
            if (!b[i][j]) ans += d[i][j];
    cout << ans;
    return 0;
}