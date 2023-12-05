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
int r[MAX + 1];
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n;i++) cin >> a[i];

    ans.push_back(a[0]);
    r[0] = 0;
    for (int i = 1; i<n;i++) {
        if (ans.back() < a[i]){
            ans.push_back(a[i]);
            r[i] = ans.size()-1;
        }
        else {
            int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[pos] = a[i];
            r[i] = pos;
        }
    }

    vector<int> ord;
    int max_val = *max_element(r, r + n);
    
    for (int i = n-1; i>=0;i--) {
        if (r[i] == max_val) {
            ord.push_back(a[i]);
            max_val--;
        }
        if (max_val < 0) break;
    }

    sort(ord.begin(), ord.end());
    cout << ans.size() << endl;
    for (int e : ord) {
        cout << e << " ";
    }

    return 0;
}