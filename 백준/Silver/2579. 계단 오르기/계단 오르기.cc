#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int a[301];
int dp[301][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n;i++) cin >> a[i];

    dp[1][1] = a[1];
    dp[2][1] = a[2];
    for (int i = 2; i <= n;i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + a[i];
        dp[i][2] = dp[i-1][1] + a[i];
    }

    cout << max(dp[n][1], dp[n][2]);
    return 0;
}