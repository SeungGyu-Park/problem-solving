#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<tuple<int, int, int>> g;
int p[10001];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) p[b] = a;
    else p[a] = b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int v, e;

    cin >> v >> e;
    
    for (int i = 0; i < e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back({c, a, b});
    }

    sort(g.begin(), g.end());
    for (int i = 1; i<=v;i++) p[i] = i;

    int ans = 0;
    for (auto nxt : g) {
        int c, a, b;
        tie(c, a, b) = nxt;
        if (find(a) != find(b)) {
            ans += c;
            uni(a, b);
        }
    }
    cout << ans;
    return 0;
}