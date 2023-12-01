#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, k;
int ana[11][11];
vector<int> res;

void dfs(int cur, int vis[11], int sum) {
    
    int flag = 0;
    for (int i = 0; i < n;i++) {
        if (!vis[i]) flag = 1;
    }

    if (!flag) {
        res.push_back(sum);
        return;
    }

    int tmp[11];
    for (int i = 0; i < n;i++) tmp[i] = vis[i];

    for (int i = 0; i < n;i++) {
        if (i == cur) continue;
        if (tmp[i]) continue;
        tmp[i] = 1;
        dfs(i, tmp, sum + ana[cur][i]);
        tmp[i] = 0;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i = 0; i <n;i++)
        for (int j = 0; j <n;j++)
            cin >> ana[i][j];

    for (int k = 0; k < n;k++)
        for (int i = 0; i< n;i++) 
            for (int j = 0; j<n;j++) 
                if (ana[i][k] + ana[k][j] < ana[i][j])
                    ana[i][j] = ana[i][k] + ana[k][j];

    int vis[11] = {0,};
    vis[k] = 1;
    dfs(k, vis, 0);
    
    int ans = *min_element(res.begin(), res.end());
    cout << ans << endl;
    return 0;
}