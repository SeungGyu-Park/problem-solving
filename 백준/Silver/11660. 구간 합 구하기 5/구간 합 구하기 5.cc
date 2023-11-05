#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

ll p[1025][1025];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int n, m;

    cin >> n >> m;

    for (int i =1; i<=n;i++) {
        for (int j = 1; j<=n;j++) {
            cin >> p[i][j];
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    
    while (m--) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        cout << p[c][d] - p[c][b-1] - p[a-1][d] + p[a-1][b-1] << endl;
    }
    return 0;
}