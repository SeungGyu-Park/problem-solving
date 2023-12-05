#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int MAX = 1'000'000;
int n;
int a[MAX + 1];
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n;i++) cin >> a[i];

    ans.push_back(a[0]);
    
    for (int i = 1; i<n;i++) {
        if (ans.back() < a[i])
            ans.push_back(a[i]);
        else {
            int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[pos] = a[i];
        }
    }

    cout << ans.size();

    return 0;
}