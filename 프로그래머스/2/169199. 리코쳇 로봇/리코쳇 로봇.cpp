#include <string>
#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
pair<int, int> startPos, endPos;
int n, m;

int oob(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int solution(vector<string> board) {
    int answer = 1e9;
    
    n = board.size();
    m = board[0].size();
    
    for (int i = 0; i < board.size();i++) {
        for (int j = 0; j < board[i].size();j++) {
            if (board[i][j] == 'R')
                startPos = {i, j};
            if (board[i][j] == 'G')
                endPos = {i, j};
        }
    }
    int dist[101][101];
    queue<pair<int, int>> q;
    
    memset(dist, -1, sizeof(dist));
    
    dist[startPos.first][startPos.second] = 0;
    q.push({startPos.first, startPos.second});
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        
        if (x == endPos.first && y == endPos.second) {
            answer = min(answer, dist[x][y]);
            continue;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x; int ny = y;
            
            while (!oob(nx + dx[dir], ny + dy[dir]) && board[nx + dx[dir]][ny + dy[dir]] != 'D') {
                nx += dx[dir];
                ny += dy[dir];
            }
            if (nx == x && ny == y) continue;
            if (dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                continue;
            }
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    if (answer == 1e9) return -1;
    return answer;
}