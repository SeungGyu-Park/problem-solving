#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

vector<int> g[100001];
vector<int> adj[100001];
int n, r, q;
int vis[100001];
int subTrees[100001];

// subtree의 정점 개수 리턴
int count_subtrees(int root) {
    vis[root] = 1;
    for (int &child : g[root]) {
        if (vis[child]) continue;
        subTrees[root] += count_subtrees(child);
    }
    return subTrees[root];
}

// root가 cur_root인 트리 만들기
int parent[100001];

void make_tree(int cur_root, int prev_root) {
    for (int &nxt_child : g[cur_root]) {
        if (nxt_child == prev_root) continue;
        adj[cur_root].push_back(nxt_child);
        parent[nxt_child] = cur_root;
        make_tree(nxt_child, cur_root);
    }
}

int cnt[100001];

void countSubtrees(int root) {
    cnt[root] = 1;
    for (int &nxt_child : adj[root]) {
        countSubtrees(nxt_child);
        cnt[root] += cnt[nxt_child];
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> r >> q;

    for (int i = 0; i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        subTrees[i+1] = 1;
    }
    subTrees[n] = 1;

    make_tree(r, -1);
    countSubtrees(r);
    
    // count_subtrees(r);
    while (q--) {
        int x; cin >> x;
        // cout << subTrees[x] << endl;
        cout << cnt[x] << endl;
    }
    return 0;
}