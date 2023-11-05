#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int a[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n;i++) {
        int x; cin >> x;
        a[x]++;
    }
    
    int res = -1;
    for (int i = 1; i<=999;i++) {
        if (!a[i]) continue;
        a[i]--;
        for (int j = 1; j<=999;j++) {
            if (!a[j]) continue;
            
            int tmp = i * j;
            int sum = 0;

            while (tmp != 0) {
                sum += tmp % 10;
                tmp /= 10;
            }
            res = max (res, sum);
        }

    }
    
    cout << res;
    return 0;
}