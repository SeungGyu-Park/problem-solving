#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define GOS 0
#define WATER 1
#define endl "\n"
using namespace std;

int r, c;
char board[51][51];
int dist[2][51][51];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> r >> c;

    queue<tuple<int, int, int>> q;
    memset(dist, -1, sizeof(dist));
    
    vector<tuple<int, int, int>> v;
    for (int i = 0;i < r;i++) {
        for (int j = 0; j < c;j++) {
            cin >> board[i][j];

            if (board[i][j] == 'S') {
                v.push_back({GOS, i, j});
                dist[GOS][i][j] = 0;
            }
            if (board[i][j] == '*') {
                v.push_back({WATER, i, j});
                dist[WATER][i][j] = 0;
            }
        }
    }
    
    sort(v.begin(), v.end(), greater<>());
    for (auto e : v) q.push(e);

    while (!q.empty()) {
        int type, x, y;
        tie(type, x, y) = q.front(); q.pop();

        if (type == GOS && board[x][y] == 'D') {
            cout << dist[GOS][x][y];
            return 0;
        }

        for (int dir = 0; dir < 4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dist[type][nx][ny] != -1) continue;
            if (board[nx][ny] == 'X') continue;
            if (type == GOS) {
                if (dist[WATER][nx][ny] >= dist[GOS][x][y]) continue;
                dist[GOS][nx][ny] = dist[GOS][x][y] + 1;
                q.push({GOS, nx, ny});
            }
            if (type == WATER) {
                if (board[nx][ny] == 'D') continue;
                dist[WATER][nx][ny] = dist[WATER][x][y] + 1;
                q.push({WATER, nx, ny});
            }
        }
    }

    cout << "KAKTUS";
    return 0;
}