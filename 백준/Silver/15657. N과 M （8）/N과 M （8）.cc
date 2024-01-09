#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int n, m;
int board[9];
int ans[9];
int visit[9];

void recur(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++){
            cout << board[ans[i]] << ' ';
        }
        cout << endl; return;
    }
    int start = idx == 0 ? 0 : ans[idx-1];
    for (int i = start; i < n; i++) {
        ans[idx] = i;
        visit[i] = 1;
        recur(idx + 1);
        visit[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i<n;i++){
        cin >> board[i];
    }
    sort(board, board + n);
    recur(0);
    return 0;
}