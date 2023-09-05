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
int board[1001][1001];
int dist[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;
    queue<pair<int, int>> q;

    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i <n;i++) {
        for (int j = 0; j <m;j++){
            cin >> board[i][j];
            if (board[i][j] ==2) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int dir = 0; dir < 4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (dist[nx][ny] != -1) continue;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < n;i++) {
        for (int j = 0; j <m;j++) {
            if (board[i][j] == 0) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}