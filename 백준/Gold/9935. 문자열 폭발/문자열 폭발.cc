#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    string str, t;
    stack<char> s1, s2;

    cin >> str >> t;

    for (int i =0; i < str.size(); i++) {
        s1.push(str[i]);
        int cur = t.size() -1;
        while (!s1.empty() && s1.top() == t[cur] && cur >= 0) {
            s1.pop();
            s2.push(t[cur]);
            cur--;
        }
        while (!s2.empty()) {
            if (cur >= 0)
                s1.push(s2.top());
            s2.pop();
        }
    }
    vector<char> res;
    if (s1.empty()) cout << "FRULA";
    else {
        while (!s1.empty()) {
            res.push_back(s1.top());
            s1.pop();
        }
        for (int i = res.size()-1 ; i>=0; i--) {
            cout << res[i];
        }
    }
    
    return 0;
}