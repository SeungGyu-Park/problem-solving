#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int a[300001];
int s[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n;i++) cin >> a[i];

	for (int i = 0; i < n - 1;i++) {
		s[i] = a[i+1] - a[i];
	}
	sort(s, s + n-1);

	ll ans = 0;
	for (int i = 0; i < n-k;i++) ans += s[i];
	cout << ans;
	return 0;
}