#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int MAX = 4'000'000;
int n;
bool p[MAX + 1];

void makePrime() {
    for (int i = 0; i<= MAX;i++)
        p[i] = true;
    p[0] = p[1] = false;
    
    for (int i = 2; i * i < MAX;i++) {
        if (!p[i]) continue;
        for (int j = i * i; j <= MAX; j +=i) {
            p[j] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    makePrime();

    vector<int> v;
    for (int i = 2; i<=MAX;i++)
        if (p[i]) v.push_back(i);

    v.push_back(0);

    int ans = 0;
    int st = 0, en = 1;
    int sum = v[0];
    while (1) {
        if (sum == n) ans++;
        if (sum <= n) sum += v[en++];
        if (sum > n) sum -= v[st++];
        if (en == v.size()) break;
    }
    cout << ans;
    return 0;
}