#include <iostream>
#include <deque>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
string p, nums;
deque<int> dq;

void parsing() {
    int x = 0;
    for (int i = 1; i + 1 < nums.size(); i++) {
        if (nums[i] == ',') {
            dq.push_back(x);
            x = 0;
        } else {
            x = x * 10 + (nums[i] - '0');
        }
    }
    if (x != 0) // 한 개일 때
        dq.push_back(x);
}

void solve() {
    int R_cnt = 0;
    for (auto cmd : p) {
        if (cmd == 'R')
            R_cnt++;
        else {
            if (!dq.empty()) {
                if (R_cnt % 2)
                    dq.pop_back();
                else 
                    dq.pop_front();
            }
            else {
                cout << "error" << endl;
                dq.clear();
                return ;
            }
        }
    }
    if (R_cnt % 2)
        reverse(dq.begin(), dq.end());

    cout << "[";
    while (!dq.empty()) {
        cout << dq.front();
        if (dq.size() != 1)
            cout << ",";
        dq.pop_front();
    }
    cout << "]" << endl;
    dq.clear();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int tc, x;

    cin >> tc;
    while(tc--) {
        cin >> p;
        cin >> n;
        cin >> nums;
        parsing();
        solve();
    }
    return 0;
}