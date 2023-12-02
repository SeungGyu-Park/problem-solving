#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> g[101];
int vis[101];
int n;

void dfs(int idx) {
    for (auto nxt : g[idx]) {
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        dfs(nxt);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i =0; i <n;i++){
        for (int j = 0;j<n;j++){
            int x; cin >> x;
            if (x) g[i].push_back(j);
        }
    }
    for (int i = 0; i <n;i++){
        memset(vis, 0, sizeof(vis));
        dfs(i);
        for (int j = 0 ; j < n;j++){
            cout << vis[j] << " ";
        }
        cout << endl;
    }
    return 0;
}