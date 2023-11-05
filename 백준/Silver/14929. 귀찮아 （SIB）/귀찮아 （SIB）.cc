#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

ll a[100001];
ll pSum[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;

    cin >> n;
    for (int i =1 ; i<=n;i++) {
        cin >> a[i];
        pSum[i] = pSum[i-1] + a[i];
    }
    
    ll ans = 0;
    // x1, x2, x3, x4
    // x1x2 + x1x3 + x1x4
    // x2x3 + x2x4
    // x3x4

    // x4(x3 + x2 + x1)
    // x3(x2 + x1)
    // x2(x1)
    for (int i = 2; i<=n;i++) {
        ans += a[i] * pSum[i-1];
    }
    cout << ans;
    return 0;
}