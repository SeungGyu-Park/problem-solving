#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
int b[101][101];
ll dp[101][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n;i++) {
		for (int j= 0; j < n;j++) {
			cin >> b[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (dp[i][j] == 0 || (i == n-1) && (j == n-1)) continue;
			
			// right
			if (j + b[i][j] < n) 
				dp[i][j + b[i][j]] += dp[i][j];
			if (i + b[i][j] < n)
				dp[i + b[i][j]][j] += dp[i][j];
			
		}
	}
	cout << dp[n-1][n-1];
	
	return 0;
}