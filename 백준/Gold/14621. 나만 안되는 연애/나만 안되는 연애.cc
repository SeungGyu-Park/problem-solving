#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m;
int vis[1001];
int r[1001];
char t[1001];
tuple<int, int, int> e[10001];

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
    for (int i = 1; i<=n;i++) {
        cin >> t[i];
        r[i] = i;
    }

    for (int i = 0; i <m;i++) {
        int a, b, c;

        cin >> a >> b >> c;
        e[i] = {c, a, b};
    }
    sort(e, e + m);

    int ans = 0;
    for (int i = 0; i< m;i++) {
        int a, b, c;

        tie(c, a, b) = e[i];

        if (t[a] == t[b]) continue;
        if (find(a) == find(b)) continue;
        vis[a] = 1;
        vis[b] = 1;
        uni(a, b);
        ans += c;
    }
    for (int i = 1; i<=n;i++) {
        if (!vis[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}