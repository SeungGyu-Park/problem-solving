#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define endl "\n"
using namespace std;

int n, k;
int ana[11][11];
int ans = 1e9;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;

    vector<int> ord;
    for (int i = 0; i <n;i++) {
        if (i != k)
            ord.push_back(i);
        for (int j = 0; j <n;j++)
            cin >> ana[i][j];
    }
        
    for (int k = 0; k < n;k++)
        for (int i = 0; i< n;i++) 
            for (int j = 0; j<n;j++) 
                ana[i][j] = min(ana[i][j], ana[i][k] + ana[k][j]);

    do {
        int sum = ana[k][ord[0]];
        for (int i = 0; i < ord.size() - 1; i++)
            sum += ana[ord[i]][ord[i+1]];
        ans = min(ans, sum);
    } while (next_permutation(ord.begin(), ord.end()));
    
    cout << ans;
    return 0;
}