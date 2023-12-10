#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int a[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i =0 ; i < n;i++) cin >> a[i];

    int st = 0, en = *max_element(a, a + n);
    int ret = 0;
    cin >> m;
    while (st <= en) {
        int mid = (st + en) / 2;
        int sum = 0;
        for (int i =0 ; i< n;i++) {
            if (a[i] >= mid) sum += mid;
            else sum += a[i];
        }
        if (sum <= m) {
            ret = mid;
            st = mid + 1;
        } else en = mid - 1;
    }
    cout << ret;
    return 0;
}