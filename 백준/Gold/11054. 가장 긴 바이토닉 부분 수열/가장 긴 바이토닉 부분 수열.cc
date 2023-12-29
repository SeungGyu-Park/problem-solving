#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int MAX = 1000;
int n;
int a[MAX + 1];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n;i++)
        cin >> a[i];

    unsigned long ans = 0;
    for (int i = 0; i < n;i++) {
        vector<int> lis;
        lis.push_back(a[0]);
        for (int j = 1; j<=i;j++) {
            if (lis.back() < a[j]) {
                lis.push_back(a[j]);
            } else {
                int pos = lower_bound(lis.begin(), lis.end(), a[j]) - lis.begin();
                lis[pos] = a[j];
            }
        }

        vector<int> lds;
        lds.push_back(a[n-1]);
        for (int j = n-2; j >= i; j--) {
            if (lds.back() < a[j]) {
                lds.push_back(a[j]);
            } else {
                int pos = lower_bound(lds.begin(), lds.end(), a[j]) - lds.begin();
                lds[pos] = a[j];
            }
        }
        ans = max(ans, lis.size() + lds.size() - 1);
    }
    cout << ans;
    return 0;
}