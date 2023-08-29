#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int deg[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    unordered_map<string, int> name_to_idx; // 이름에 대한 인덱스
    unordered_map<int, string> idx_to_name; // 인덱스에 대한 이름
    vector<string> v; // 이름 저장
    vector<int> adj[1001]; // 순서 저장 그래프
    vector<string> tree[1001]; // 순서 저장 그래프로 만든 트리

    cin >> n;
    for (int i = 1; i <= n;i++) {
        string str; cin >> str;
        name_to_idx[str] = i;
        idx_to_name[i] = str;
        v.push_back(str);
    }
    cin >> m;
    while (m--) {
        string x, y;
        cin >> x >> y;
        adj[name_to_idx[y]].push_back(name_to_idx[x]);
        deg[name_to_idx[x]]++;
    }
    vector<int> root;
    for (int i = 1; i<=n;i++) {
        if (deg[i] == 0) {
            root.push_back(i);
        }
    }

    vector<string> ord;
    for (int e : root) {
        if (deg[e]) continue;
        queue<int> q;
        ord.push_back(idx_to_name[e]);
        q.push(e);
        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            cnt++;
            for (int nxt : adj[cur]) {
                if (--deg[nxt] == 0) {
                    q.push(nxt);
                    tree[cur].push_back(idx_to_name[nxt]);
                }
            }
        }
    }

    sort(ord.begin(), ord.end());
    cout << ord.size() << endl;
    for (auto e : ord) {
        cout << e << " ";
    }
    cout << endl;
    for (int i = 1; i<=n;i++)
        sort(tree[i].begin(), tree[i].end());

    sort(v.begin(), v.end());
    for (string s : v) {
        cout << s << " " << tree[name_to_idx[s]].size() << " ";
        for (string nxt : tree[name_to_idx[s]]) {
            cout << nxt << " ";
        }
        cout << endl;
    }

    return 0;
}