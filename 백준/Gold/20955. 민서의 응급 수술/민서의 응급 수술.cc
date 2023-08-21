#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int p[100'100];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void union_group(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) p[b] = a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;
    for (int i = 1; i<=n;i++) p[i] = i;
    
    int res = 0;
    while (m--) {
        int u, v;
        cin >> u >> v;

        if (find(u) != find(v)) union_group(u, v);
        else res++;
    }
    for (int i = 1; i<=n;i++) {
        // 자기 자신 -> cycle 
        if (i == find(i)) res++;
    }
    cout << res -1;
    return 0;
}