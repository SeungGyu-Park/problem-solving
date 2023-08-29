#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
int deg[1001];
vector<int> adj[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    while(m--) {
        int num;
        cin >> num;
        vector<int> tmp;
        for (int i = 0; i<num;i++){
            int x; cin >> x;
            tmp.push_back(x);
        }
        for (int i = 0; i < tmp.size()-1;i++){
            adj[tmp[i]].push_back(tmp[i+1]);
            deg[tmp[i+1]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i<=n;i++){
        if (deg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (int nxt : adj[cur]) {
            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    if (ans.size() == n) {
        for (int x : ans) cout << x << ' ';
    }
    else cout << 0;
    return 0;
}