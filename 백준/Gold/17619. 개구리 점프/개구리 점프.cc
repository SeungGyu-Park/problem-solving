#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, q;
int r[100001];
tuple<int, int, int, int> e[100001];

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

    cin >> n >> q;

    for (int i = 1; i<=n;i++) r[i] = i;

    for (int i = 1; i <= n;i++) {
        int a, b, c;

        cin >> a >> b >> c;

        e[i] = {a, b, c, i};
    }
    sort(e+1, e + n + 1);
    
    for (int i = 2; i<=n;i++) {
        int x1, x2, y, ord;
        int px1, px2, py, pord;

        tie(x1, x2, y, ord) = e[i];
        tie(px1, px2, py, pord) = e[i-1];
        if (px1 <= x1 && x1 <= px2) {
            if (px2 > x2) get<1>(e[i]) = px2;
            get<0>(e[i]) = px1;
            uni(pord, ord);
        }
    }

    while (q--) {
        int a, b;

        cin >> a >> b;
        if (find(a) == find(b)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}