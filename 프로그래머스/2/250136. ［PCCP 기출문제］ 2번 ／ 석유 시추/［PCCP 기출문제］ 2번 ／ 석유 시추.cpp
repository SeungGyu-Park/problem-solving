#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> board[501][501];
int vis[501][501];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n, m;
int val[50001];
int idx = 0;

bool oob(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void bfs(int i, int j, vector<vector<int>> &land) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> pos;
    int cnt = 0;
    
    vis[i][j] = 1;
    q.push({i, j});
    
    while (!q.empty()) {
        int x, y;
        
        tie(x, y) = q.front(); q.pop();
        pos.push_back({x, y});
        cnt++;
        
        for (int dir = 0; dir < 4;++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (oob(nx, ny)) continue;
            if (!land[nx][ny]) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    for (auto &e : pos) {
        board[e.first][e.second].first = cnt;
        board[e.first][e.second].second = idx;
    }
    val[idx++] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    
    for (int i =0 ; i < n; ++i) {
        for (int j = 0 ;j < m; ++j) {
            if (vis[i][j] || !land[i][j]) continue;
            bfs(i, j, land);
        }
    }
    
    for (int i = 0 ; i < m; ++i) {
        set<int> s;
        int sum = 0;
        
        for (int j = 0; j < n; ++j) {
            if (!board[j][i].first) continue;
            s.insert(board[j][i].second);
        }
        for (auto e : s)
            sum += val[e];
        answer = max(answer, sum);
    }
    return answer;
}