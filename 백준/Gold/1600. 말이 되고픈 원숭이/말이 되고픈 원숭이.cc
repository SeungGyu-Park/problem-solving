#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;


int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ddx[8] = {-1,-2,-2,-1,1,2,2,1};
int ddy[8] = {-2,-1,1,2,2,1,-1,-2};
int k, w, h;
int board[201][201];
int dist[32][201][201];

int oob(int x, int y) {
    return (x < 0 || x >= h || y < 0 || y >= w);
}
void Solve() {
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;

    dist[0][0][0] = 0;
    q.push({0,0,0});
    while (!q.empty()) {
        int cur_k, x, y;
        tie(cur_k, x, y) = q.front();
        q.pop();
        if (x == h-1 && y == w-1) {
            cout << dist[cur_k][h-1][w-1]; return;
        }
        if (cur_k < k) {
            for (int dir = 0; dir < 8;dir++){
                int nx = x + ddx[dir];
                int ny = y + ddy[dir];

                if (oob(nx, ny)) continue;
                if (board[nx][ny]) continue;
                if (dist[cur_k+1][nx][ny] != -1) continue;
                dist[cur_k + 1][nx][ny] = dist[cur_k][x][y] + 1;
                q.push({cur_k+1, nx, ny});
            }
        }
        for (int dir = 0; dir < 4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (oob(nx, ny)) continue;
            if (board[nx][ny]) continue;
            if (dist[cur_k][nx][ny] != -1) continue;
            dist[cur_k][nx][ny] = dist[cur_k][x][y] + 1;
            q.push({cur_k, nx, ny});
        }
    }
    cout << -1 << endl;
}

void Input() {
    cin >> k;
    cin >> w >> h;
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++){
            cin >> board[i][j];
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    Input();
    Solve();
    
    return 0;
}