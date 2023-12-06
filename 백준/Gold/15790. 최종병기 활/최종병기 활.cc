#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m, k;
int a[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    for (int i = 0; i < m;i++) cin >> a[i];

    int st = 0, en = n;
    int ret =1e9;
    while (st <= en) {
        int mid = (st + en) / 2;

        int cnt = 0;
        for (int i = 0; i < m;i++) {
            int prev = a[i];
            cnt = 0;
            for (int j= i + 1; j < m + i + 1; j++) {
                int tmp = a[j%m] - prev;
                if (tmp <= 0) tmp += n;
                if (tmp < mid) continue;
                cnt++;
                prev = a[j%m];
            }
            if (cnt >= k) {
                break;
            }
        }
        if (cnt >= k) {
            st = mid + 1;
            ret = mid;
        } else en = mid -1;
    }
    if (ret == 1e9) ret = -1;
    cout << ret << endl;
    return 0;
}