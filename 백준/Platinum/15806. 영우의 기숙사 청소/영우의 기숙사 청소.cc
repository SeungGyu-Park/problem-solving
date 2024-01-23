#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;


int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int board[2][301][301];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int n, m, k, t, a, b;
	queue<tuple<int, int, int>> q;
	cin >> n >> m >> k >> t;

	while (m--) {

		cin >> a >> b;
		q.push({0, a, b});
		board[0][a][b] = 1;
	}

	while (!q.empty()) {
		int cur, x, y;

		tie(cur, x, y) = q.front(); q.pop();
		if (cur >= t) continue;
		bool flag = false;
		for (int dir = 0; dir < 8;dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (board[(cur+1)%2][nx][ny]) continue;
			board[(cur+1)%2][nx][ny] = true;
			q.push({cur+1, nx, ny});
			flag = true;
		}
		if (!flag) board[cur%2][x][y] = false;
	}
	while (k--) {

		cin >> a >> b;

		if (board[t%2][a][b]) {
			cout << "YES"; return 0;
		}
	}
	cout << "NO";
	return 0;
}