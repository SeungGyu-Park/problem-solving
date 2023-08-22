#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

vector<int> g[100'001];
int score[100'001];

void dfs(int root) {
    for (int &nxt_child : g[root]) {
        score[nxt_child] += score[root];
        dfs(nxt_child);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, m;
    
    cin >> n >> m;
    for (int i = 1; i<=n;i++) {
        int c; cin >> c;
        // c의 자식은 i
        if (c != -1)
            g[c].push_back(i);
    }

    while (m--) {
        int v, w;
        cin >> v >> w;
        score[v] += w;
    }
    dfs(1);
    for (int i = 1 ; i<=n;i++) cout << score[i] << " ";
    return 0;
}