#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int r[1000001];

int find(int x) {
    if (x == r[x]) return x;
    return r[x] = find(r[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) r[b] = a;
    else r[a] = b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <=n;i++) r[i] = i;

    while (m--) {
        int t, a, b;

        cin >> t >> a >> b;

        if (t == 0) {
            if (find(a) != find(b)) uni(a, b);
        }
        else {
            if (find(a) == find(b)) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
        }
    }
    return 0;
}