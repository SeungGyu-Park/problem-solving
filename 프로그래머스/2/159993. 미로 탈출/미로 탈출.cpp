#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
pair<int, int> startPos, endPos, leverPos;

int solution(vector<string> maps) {
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    for (int i = 0; i < maps.size();i++) {
        for (int j = 0; j < maps[i].size();j++) {
            if (maps[i][j] == 'S') startPos = {i,j};
            else if (maps[i][j] == 'E') endPos = {i, j};
            else if (maps[i][j] == 'L') leverPos = {i, j};
        }
    }
    
    queue<pair<int, int>> q;
    int dist[101][101];
    memset(dist, -1, sizeof(dist));
    q.push({startPos.first, startPos.second});
    dist[startPos.first][startPos.second] = 0;
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        
        for (int dir = 0; dir < 4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[leverPos.first][leverPos.second] == -1) return -1;
    answer = dist[leverPos.first][leverPos.second];
    cout << answer << "\n";
    q.push({leverPos.first, leverPos.second});
    memset(dist, -1, sizeof(dist));
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        
        for (int dir = 0; dir < 4;dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 'X') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if (dist[endPos.first][endPos.second] == -1) return -1;
    
    return answer + dist[endPos.first][endPos.second] + 1;
}