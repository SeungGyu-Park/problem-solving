#include <iostream>
#include <algorithm>
#define ll long long

#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // freopen("input.txt", "r", stdin);

    int n;
    int arr[100001];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >>arr[i];

    sort(arr, arr + n, greater<>());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i]-i <= 0) break;
        ans += arr[i] - i;
    }
    cout << ans << endl;
    return 0;
}