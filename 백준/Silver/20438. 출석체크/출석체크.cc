#include <iostream>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int p[5005];
int vis[5005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // 3, 6, 9, 12, 5, 10
    // 출석한 학생의 누적 합을 저장한다.
    // 구간의 학생 수 ex) 3, 12 -> 9
    // - 12까지 출석한 학생의 수
    // + 3-1까지 출석한 학생의 수

    int n, k, q, m;

    cin >> n >> k >> q >> m;
    
    while (k--) {
        int x; cin >> x;
        vis[x] = -1;
    }
    while (q--) {
        int x; cin >> x;
        if (vis[x] == -1) continue;
        for (int i = x; i <= n + 2; i += x) {
            if (vis[i] == -1) continue;
            vis[i] = 1;
        }
    }
    for (int i = 3; i<=n+2;i++) {
        if (vis[i] <= 0)
            p[i] = p[i-1];
        else
            p[i] += p[i-1] + 1;
    }

    // for (int i = 3; i<=n+2;i++) {
    //     cout << vis[i] << "  ";
    // } 
    // cout << endl;
    // for (int i = 3; i<=n+2;i++) {
    //     cout << p[i] << "  ";
    // }
    // cout << endl;
    while (m--) {
        int a, b;

        cin >> a >> b;
        int ans = b-a+1 - p[b] + p[a-1] ;
        if (ans < 0) ans = 0;
        cout << ans << endl;
    }

    return 0;
}