#include <iostream>
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

    set<string> dict;
    string wolf = "wolf";

    for (int i = 0 ; i < 12;i++) {
        string tmp;
        for (int j = 0; j < 4;j++) {
            for (int k = 0; k <= i;k++) {
                tmp += wolf[j];
            }
        }
        dict.insert(tmp);
    }

    string str;

    cin >> str;

    int cur = 0;
    
    while (cur < str.size()) {
        int idx = str.find('f', cur);
        if (idx == -1) {
            cout << 0; return 0;
        }

        while (str[idx] == 'f') idx++;
        string tmp = str.substr(cur, idx-cur);
        if (dict.find(tmp) == dict.end()) {
            cout << 0; return 0;
        }
        cur = idx;
    }
    cout << 1;
    return 0;
}