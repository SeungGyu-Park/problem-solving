#include <iostream>
#include <sstream>
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

    string str;

    cin >> str;

    stringstream ss(str);
    string tmp;
    
    int res = 0;
    bool flag = false;
    while (getline(ss, tmp, '-')) {
        stringstream ss2(tmp);
        string tmp2;
        int sum = 0;
        while (getline(ss2, tmp2, '+')) {
            sum += stoi(tmp2);
        }

        if (flag) res -= sum;
        else res += sum;
        
        flag = true;
    }
    cout << res;
    return 0;
}