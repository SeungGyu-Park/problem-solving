#include <iostream>
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

    int t, x, s = 0;
    string cmd;

    cin >> t;

    while (t--) {
        cin >> cmd;
        
        if (cmd == "all") {
            s = (1 << 20) - 1;
            continue;
        }
        if (cmd == "empty") {
            s = 0; continue;
        }

        cin >> x;
        if (cmd == "add") {
            s |= (1 << (x-1));
        }
        else if (cmd == "remove") {
            s &= s ^ (1 << (x-1));
        }
        else if (cmd == "check") {
            cout << ((s & (1 << (x-1))) != 0) << endl;
        }
        else if (cmd == "toggle") {
            s ^= (1 << (x-1));
        }
    }
    return 0;
}