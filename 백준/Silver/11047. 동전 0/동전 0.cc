#include <iostream>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, k;
    vector<int> v;

    cin >> n >> k;
    for (int i = 0; i< n;i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    int ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        ans += k / v[i];
        k = k % v[i];
    }
    cout << ans;
    return 0;
}