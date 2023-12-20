#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
int arr[100001];
int dp[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i= 1; i<=n;i++)
        cin >> arr[i];
    for (int i= 1; i<=n;i++)
        dp[i] = dp[i-1] + arr[i];
    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << endl;
    }
    return 0;
}