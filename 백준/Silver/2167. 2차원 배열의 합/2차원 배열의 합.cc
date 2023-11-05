#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

ll p[301][301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m, k;

    cin >> n >> m;

    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<=m;j++) {
            cin >> p[i][j];
            p[i][j] += p[i][j-1] + p[i-1][j] - p[i-1][j-1]; 
        }
    }
    
    cin >> k;

    while(k--) {
        int a1, a2, b1, b2;

        cin >> a1 >> a2 >> b1 >> b2;

        cout << p[b1][b2] - p[b1][a2-1] - p[a1-1][b2] + p[a1-1][a2-1] << endl;
    }
    return 0;
}