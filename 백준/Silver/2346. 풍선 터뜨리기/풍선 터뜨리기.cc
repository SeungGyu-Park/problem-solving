#include <iostream>
#include <deque>
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

    int n;

    cin >> n;

    deque<pair<int, int>> dq;
    for (int i = 0; i < n;i++) {
        int x; cin >> x;
        dq.push_back({i+1, x});
    }
    // 3 2 1 -3 -1
    while (!dq.empty()) {
        int idx, p;
        tie(idx, p) = dq.front(); dq.pop_front();
        cout << idx << " ";
        if (dq.empty()) break;
        if (p > 0) {
            for (int i = 0; i < p-1;i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            for (int i = 0; i < p * -1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}