#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int board[10][10];
int ans = 1e9;
int p[6];

bool possible(int x, int y, int size) {

    if (x + size > 10 || y + size > 10) return false;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board[i][j] != 1) return false;
        }
    }

    return true;
}

bool check() {
    
    for (int i = 0; i < 10;i++) {
        for (int j = 0 ;j < 10;j++) {
            if (board[i][j]) return false;
        }
    }
    return true;
}

void put(int x, int y, int size, int v) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            board[i][j] = v;
        }
    }
}

void dfs(int x, int y, int cnt) {
    
    if (ans <= cnt) return;

    if (y == 10)
        ++x, y = 0;

    if (x == 10) {
        ans = min(ans, cnt);
        return;
    }
    
    if (!board[x][y]) {
        dfs(x, y + 1, cnt);
        return;
    }
    for (int s = 5; s >= 1; s--) {
        if (p[s] > 0 && possible(x, y, s)) {
            p[s]--;
            put(x, y, s, 0);
            dfs(x, y + s, cnt+1);
            p[s]++;
            put(x, y, s, 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);    
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    fill(p + 1, p + 6, 5);
    for (int i = 0; i< 10;i++) {
        for (int j = 0; j < 10;j++) {
            cin >> board[i][j];
        }
    }

    dfs(0,0,0);
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}