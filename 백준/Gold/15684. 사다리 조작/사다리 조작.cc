#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m, h;
bool la[31][11];
int ans = 1e9;
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

    if (check()) {
        cout << 0; return 0;
    }

    for (int i = 0; i < pos.size(); i++) {
        la[pos[i].first][pos[i].second] = true;
        if (check()) ans = min(ans, 1);

        for (int j = i + 1; j < pos.size(); j++) {
            la[pos[j].first][pos[j].second] = true;
            if (check()) ans = min(ans, 2);
            
            for (int k = j + 1; k < pos.size(); k++) {
                la[pos[k].first][pos[k].second] = true;
                if (check()) ans = min(ans, 3);
                la[pos[k].first][pos[k].second] = false;
            }
            la[pos[j].first][pos[j].second] = false;
        }
        la[pos[i].first][pos[i].second] = false;
    }
    if (ans == 1e9) ans = -1;
    cout << ans;
    return 0;
}