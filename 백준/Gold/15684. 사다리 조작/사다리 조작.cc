#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m, h;
bool la[32][12];
bool flag = false;
vector<pair<int, int>> pos;

// 아래로 내려가야 하는디. i번째 줄에 위치해야 한다.
bool check() {

    for (int i = 1; i<=n;i++) {
        int cur = i;
        for (int j = 1; j<=h;j++) {
            if (la[j][cur]) cur++;
            else if (la[j][cur-1]) cur--;
        }
        if (cur != i) return false;
    }
    return true;
}

void dfs(int st, int d, int maxx) {
    if (d == maxx) {
        if (check()) {
            cout << d;
            flag = true;
        }
        return;
    }

    for (int i = st; i < pos.size();i++) {
        la[pos[i].first][pos[i].second] = true;
        dfs(i+1, d+1, maxx);
        if (flag) return;
        la[pos[i].first][pos[i].second] = false;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m >> h;

    while (m--) {
        int x, y;

        cin >> x >> y;
        la[x][y] = true;
    }

    for (int i = 1; i<=h;i++) {
        for (int j = 1; j < n;j++) {
            if (la[i][j]) continue;
            pos.push_back({i, j});
        }
    }

    for (int i = 0; i < 4;i++) {
        dfs(0, 0, i);
        if (flag) break;
    }
    if (!flag) cout << -1;
    return 0;
}