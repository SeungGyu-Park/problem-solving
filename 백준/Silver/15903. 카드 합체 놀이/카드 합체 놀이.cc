#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        pq.push(x);
    }

    ll res = 0;
    while (m--) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    while (!pq.empty()) {
        res += pq.top(); pq.pop();
    }
    cout << res;
    return 0;
}