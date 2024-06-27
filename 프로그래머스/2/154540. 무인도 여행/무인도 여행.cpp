#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int vis[101][101];

int bfs(int i, int j, vector<string>& map) {
    queue<pair<int, int>> q;
    
    vis[i][j] = 1;
    q.push({i, j});
    int sum = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        sum += map[x][y] - '0';
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= map.size() || ny < 0 || ny >= map[0].size()) continue;
            if (map[nx][ny] == 'X') continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0;i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (vis[i][j] || maps[i][j] == 'X') continue;
            answer.push_back(bfs(i, j, maps));
        }
    }
    if (answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}