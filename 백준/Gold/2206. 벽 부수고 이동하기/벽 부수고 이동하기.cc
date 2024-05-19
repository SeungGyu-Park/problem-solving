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
int n, m;
string Map[1001];
int dist[1001][1001][2]; // 0 안부숨, 1 부숨

void bfs() {
    // x, y, broken
    queue<tuple<int, int, int>> q;

    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = dist[0][0][1] = 1;
    q.push({0, 0, 0});
    
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        q.pop();
        if (x == n-1 && y == m-1) {
            cout << dist[x][y][broken]; return;
        }
        for (int dir = 0; dir < 4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽 안부술경우
            if (Map[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }
            // 벽 부순 경우
            if (!broken && Map[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    cout << -1 << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 0; i <n;i++) {
        cin >> Map[i];
    }
    bfs();
    return 0;
}