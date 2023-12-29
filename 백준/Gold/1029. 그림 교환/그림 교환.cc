#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int a[16][16];
int dp[16][(1 << 16)];

int dfs(int root, int bits, int pre) {

    if (dp[root][bits] != 0) return dp[root][bits];
    
    for (int i = 1; i < n;i++) {
        int tmp = 1 << i;

        if (tmp & bits) continue;
        if (a[root][i] < pre) continue;
        dp[root][bits] = max(dp[root][bits], 1 + dfs(i, bits + tmp, a[root][i]));
    }

    return dp[root][bits];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    string str;
    for (int i = 0 ; i < n;i++) {
        cin >> str;
        for (int j = 0; j < n;j++) {
            a[i][j] = str[j] -'0';
        }
    }

    cout << dfs(0,1,0) + 1 << endl;
    return 0;
}