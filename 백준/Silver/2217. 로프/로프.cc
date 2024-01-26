#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;
    int w[100001];

    cin >> n;

    for (int i = 0 ; i < n;i++) cin >> w[i];

    sort(w, w + n);
    
    int ans = 0;
    for (int i = 0 ; i < n;i++)
        ans = max(ans, w[i] * (n-i));
    cout << ans;
    return 0;
}