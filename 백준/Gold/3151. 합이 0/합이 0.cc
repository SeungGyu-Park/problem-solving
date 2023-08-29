#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int arr[10001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    ll cnt = 0;
    for (int i = 0; i <n;i++) {
        for (int j = i+1; j < n;j++) {
            int tmp = arr[i] + arr[j];
            int st = j+1;
            int en = n;
            if (binary_search(arr + st, arr + en, -tmp)) {
                cnt += upper_bound(arr + st, arr + en, -tmp)-lower_bound(arr + st, arr + en, -tmp);
            }
        }
    }
    cout << cnt;
    return 0;
}