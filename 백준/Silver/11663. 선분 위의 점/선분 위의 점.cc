#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int a[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 0; i < n;i++) cin >> a[i];

    sort(a, a + n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        
        cout << (upper_bound(a, a + n, y) - a) - (lower_bound(a, a + n, x) - a) << endl;
    }
    return 0;
}