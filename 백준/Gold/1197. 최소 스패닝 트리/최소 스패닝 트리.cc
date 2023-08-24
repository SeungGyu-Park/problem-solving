#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
int root[100001];
vector<tuple<int, int, int>> edge;

int find(int x) {
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
}

void union_tree(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) root[b] = a;
    else root[a] = b;
}
// 부모가 같다면 같은 트리로 묶임.
bool find_parent(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 1;
    return 0;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin  >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    for (int i = 1; i<=n;i++)
        root[i] = i;
    sort(edge.begin(), edge.end());
    int ans = 0;
    for (int i = 0; i < edge.size();i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if (!find_parent(a, b)) {
            ans += cost;
            union_tree(a, b);
        }
    }
    cout << ans << endl;
    return 0;
}