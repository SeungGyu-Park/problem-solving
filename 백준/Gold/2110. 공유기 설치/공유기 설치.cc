#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, c;
int h[200001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> c;

    for (int i = 0; i <n;i++) cin >> h[i];
    
    sort(h, h + n);
    int st = 0, en = h[n-1];
    int ret = 1e9;

    while (st <= en) {
        int mid = (st + en) / 2;
        
        int cnt = 1;
        int lt = 0, rt = 1;
        while (lt < rt && rt < n && lt < n) {
            int diff = h[rt]- h[lt];
            
            if (diff >= mid) {
                cnt++;
                lt = rt;
            } 
            rt++;
        }
        if (cnt >= c) {
            st = mid + 1;
            ret = mid;
        } else {
            en = mid - 1;
        }
    }
    cout << ret;
    return 0;
}