#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int d[101][101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    const int n = 100;

    for (int i = 1; i<=n;i++) {
        for (int j = 1; j<= n;j++) {
            d[i][j] = 10000;
            if (i == n || j == n) d[i][j] = 4999;
        }
        d[i][i] = 0;
    }

    cout << n << endl;
    for (int i = 1; i<=n;i++)
        for (int j = 1; j<=n;j++)
            cout << d[i][j] << " ";
        cout << endl;
    return 0;
}