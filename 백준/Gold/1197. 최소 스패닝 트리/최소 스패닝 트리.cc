#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int r[10001];
tuple<int, int, int> edge[100001];

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

    int v, e;

    cin >> v >> e;

    for (int i =1;i <= v;i++) r[i] = i;

    for (int i =0 ; i < e;i++) {
        int a, b, c;

        cin >> a >> b >> c;

        edge[i] = {c, a, b};
    }
    sort(edge, edge + e);

    int ans = 0;
    for (int i =0 ; i < e;i++) {
        int a, b, c;
        tie(c, a, b) = edge[i];

        if (find(a) == find(b)) continue;
        uni(a, b);
        ans += c;
    }

    cout << ans;
    return 0;
}