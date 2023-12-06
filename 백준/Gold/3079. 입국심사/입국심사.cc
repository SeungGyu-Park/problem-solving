#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ull unsigned long long
#define ll long long
#define endl "\n"
using namespace std;

const int MAX = 100'000;
ull a[MAX + 1];
ull n, m;

int solve(ull t) {

    ull cnt = 0;
    for (int i = 0; i< n;i++) {
        cnt += (t / a[i]);
    }

    return cnt >= m;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n;i++) cin >> a[i];

    sort(a, a + n);
    ull st = 0, en = m * a[n-1];
    ull ret = 0;
    while (st <= en) {
        ull mid = (st + en) / 2;

        if (solve(mid)) {
            if (ret == 0 || ret > mid)
                ret = mid;
            en = mid - 1;
        } else st = mid + 1;
    }

    cout << ret;
    return 0;
}