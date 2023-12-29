#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int a[16][16];
int dp[16][(1 << 16) + 1];

// 0부터 시작할 것.
// dp 테이블 초기값은?
// dp 테이블이 반환하는 것
// root부터 시작하여 bits를 이루는 경로를 거친 최소 거리
int dfs(int root, int bits) {

    if (bits == (1 << n) - 1) {
        if (a[root][0] == 0) // 돌아갈 수 없음 -> 이 경우는 갱신되어야 함. 최대값을 반환하여 갱신시킨다.
            return 1e9;
        // bits가 다 돌았으면 root에서 모든 경로를 순회한 것이다.
        // 처음에 root를 0으로 설정하였으므로 root에서 0으로 가는 경로까지 반환
        return a[root][0];
    }

    if (dp[root][bits] != -1) return dp[root][bits];
    dp[root][bits] = 1e9;

    for (int i = 0; i < n;i++) {
        int tmp = 1 << i;

        // 갈 수 없음
        if (a[root][i] == 0) continue;
        // 방문함.
        if (bits & tmp) continue;
        // root 부터 bits를 거친 최종 경로가 반환되어야 한다.
        // 다음 bits 는 bits + tmp
        dp[root][bits] = min(a[root][i] + dfs(i, bits + tmp), dp[root][bits]);
    }
    return dp[root][bits];
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n;i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    memset(dp, -1, sizeof(dp));
    
    cout << dfs(0, 1) << endl;
    return 0;
}