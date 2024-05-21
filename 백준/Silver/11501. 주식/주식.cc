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

    int tc;

    cin >> tc;

    while (tc--) {
        int n;
        int a[1000001] = {0,};

        cin >> n;

        for (int i = 0; i < n;i++)
            cin >> a[i];

        int idx1 = n-1;
        int idx2 = n-2;
        ll res = 0;

        while (idx1 >= 1 && idx2 >= 0) {

            while (idx2 >= 0 && a[idx1] >= a[idx2]) {
                res += a[idx1] - a[idx2--];
            }
            idx1 = idx2;
            idx2 = idx1-1;
        }
        cout << res << endl;
    }
    return 0;
}