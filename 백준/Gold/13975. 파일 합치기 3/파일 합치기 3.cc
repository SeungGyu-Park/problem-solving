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

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<>> pq;
        while (n--) {
            int x; cin >> x;
            pq.push(x);
        }
        ll res = 0;
        while (pq.size() != 1) {
            ll f1 = pq.top(); pq.pop();
            ll f2 = pq.top(); pq.pop();
            res += (f1 + f2);
            pq.push(f1 + f2);
        }
        cout << res << endl;
    }
    return 0;
}