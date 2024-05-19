#include <iostream>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int LMT = 1000000;
int n, m;
ll a[LMT];

bool possible(int len) {
    ll cnt = 0;

    for (int i = 0; i <n;i++){
        if (a[i] > len)
            cnt += a[i] - len;
    }
    return cnt >= m;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    ll maxx = -1;
    for (int i = 0; i <n;i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }

    ll st = 1, en = maxx;
    ll res = 0;
    while (st <= en) {
        ll mid = (st + en)/2;
        if (possible(mid)) {
            st = mid + 1;
            res = mid;
        } else
            en = mid - 1;
    }
    cout << res;
    return 0;
}