#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
vector<int> g[51];
int vis[51];
int p[51];
int del;
int cnt;

void dfs(int root) {
    if (root == del) return;
    if (g[root].size() == 0) {
        cnt++;
        return;
    }
    if (g[root].size() == 1 && del == g[root][0]) {
        cnt++; return;
    }
    vis[root] = 1;
    for (int &nxt_child : g[root]) {
        if (vis[nxt_child]) continue;
        if (nxt_child == del) continue;
        dfs(nxt_child);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int root;
    cin >> n;

    for (int i = 0; i <n;i++) {
        int x;cin >> x;
        p[i] = x;
        if (x == -1) {
            root = i;
            continue;
        }
        g[x].push_back(i);
    }
    cin >> del;
    if (n == 1) {
        if (del == root) {
            cout << 0;
        }
        else cout << 1;
        return 0;
    }
    dfs(root);
    cout << cnt;
    return 0;
}