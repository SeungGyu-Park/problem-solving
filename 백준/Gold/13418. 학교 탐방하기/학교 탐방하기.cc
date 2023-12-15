#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int r[1001];
vector<tuple<int, int, int>> e;

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

    for (int i = 0; i<=n;i++) r[i] = i;

    for (int i = 0; i < m+1;i++) {
        int a, b, c;

        cin >> a >> b >> c;
        e.push_back({c, a, b});
    }

    sort(e.begin()+1, e.end());
    // 최소
    int ans = 0;
    for (int i = 0; i < m+1;i++) {
        int a, b, c;
        tie(c, a, b) = e[i];

        if (find(a) == find(b)) continue;
        uni(a, b);
        if (c == 0) ans++;
        // ans += c;
    }

    int ans2 = 0;
    for (int i = 0; i <= n;i++) r[i] = i;
    reverse(e.begin()+1, e.end());

    for (int i= 0; i < m+1;i++) {
        int a, b, c;

        tie(c, a, b) = e[i];
        if (find(a) == find(b)) continue;
        uni(a, b);
        if (c == 0) ans2++;
        // ans2 += c;
    }
    cout << ans * ans - ans2 * ans2;
    return 0;
}