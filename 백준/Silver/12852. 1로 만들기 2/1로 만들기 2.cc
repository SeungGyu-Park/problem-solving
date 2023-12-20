#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
int dp[1000001];
int idx[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    dp[1] = 0;
    for (int i = 2; i <=n;i++){
        dp[i] = dp[i-1] + 1;
        idx[i] = i-1;
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            idx[i] = i/3;
        }
        if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            idx[i] = i/2;
        }
    }

    cout << dp[n] << endl;
    int x = n;
    while (1) {
        cout << x << ' ';
        if (x == 1) break;
        x = idx[x];
    } 
    return 0;
}