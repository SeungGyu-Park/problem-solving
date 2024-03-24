#include <iostream>
#define endl "\n"
using namespace std;

int n, m;
int ans[9];
int visit[9];

void recur(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << endl; return;
    }
    for (int i = 1; i <= n; i++) {
        ans[idx] = i;
        visit[i] = 1;
        recur(idx + 1);
        visit[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    recur(0);    
    return 0;
}