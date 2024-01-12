#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int l[3'000'001];
int r[3'000'001];
vector<int> idx;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    string str;

    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'K') {
            cnt++; continue;
        }
        idx.push_back(i);
        l[i] = cnt;
    }

    cnt = 0;
    for (int i = str.size() - 1; i>=0;i--) {
        if (str[i] == 'K') {
            cnt++; continue;
        }
        r[i] = cnt;
    }

    int lt = 0, rt = idx.size() -1;
    int ans = 0;

    while (lt <= rt) {

        ans = max(ans, (rt - lt + 1) + 2 * (min(l[idx[lt]], r[idx[rt]])));
        if (l[idx[lt]] < r[idx[rt]]) {
            lt++;
        } else rt--;
    }
    cout << ans;
    return 0;
}