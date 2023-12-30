#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, k, s;
string words[51];
vector<char> ord;
set<char> dict;
int ans = 0;
int vis[51];

void init() {
    
    // anta tica
    string tmp = "antatica";
    for (int i = 0 ; i < tmp.size(); i++) {
        s |= 1 << (tmp[i] - 'a');
        dict.insert(tmp[i]);
    }
}

void dfs(int start, int depth) {

    if (depth <= k) {

        int cnt = 0;
        for (int i = 0; i< n;i++) {
            int flag = 1;
            for (int j = 0 ; j < words[i].size(); j++) {
                if ((s & (1 << (words[i][j] - 'a'))) == 0) {
                    flag = 0; break;
                }
            }
            if (flag) cnt++;
        }
        ans = max(ans, cnt);
    }

    for (int i = start; i < ord.size();i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        s |= (1 << (ord[i] - 'a'));
        dfs(i, depth+1);
        s ^= (1 << (ord[i] - 'a'));
        vis[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> k;

    if (k < 5) {
        cout << 0; return 0;
    }
    init();
    for (int i = 0; i < n;i++) {
        cin >> words[i];

        for (int j = 0; j < words[i].size(); j++) {
            if ((s & (1 << (words[i][j] - 'a'))) != 0) continue;
            if (dict.find(words[i][j]) != dict.end()) continue;
            dict.insert(words[i][j]);
            ord.push_back(words[i][j]);
        }
    }
    sort(ord.begin(), ord.end());
    k -= 5;

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}