#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    string str;

    cin >> str;

    stack<int> s;
    vector<pair<int, int>> pos;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(i);
        } else if (str[i] == ')') {
            pos.push_back({s.top(), i});
            s.pop();
        }
    }

    set<string> ans;
    for (int i = 1; i < (1 << pos.size()); i++) {
        int tmp = i;
        string s;
        bool vis[201];
        fill(vis, vis + 201, false);
        for (int j = 0; j < pos.size(); j++) {
            if (tmp % 2 == 1) {
                vis[pos[j].first] = true;
                vis[pos[j].second] = true;
            }
            tmp /= 2;
        }
        for (int j = 0; j < str.size(); j++) {
            if (vis[j]) continue;
            s += str[j];
        }
        ans.insert(s);
    }

    for (string s : ans)
        cout << s << endl;
    return 0;
}