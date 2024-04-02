#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n, m, l;
int a[1001];

bool cut(int mid, int t) {

	int prev = 0;
	int cnt = 0;
	for (int i = 0; i <=m;i++) {
		if (a[i] - prev >= mid) {
			cnt++;
			prev = a[i];
		}
	}

	return cnt <= t;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n >> m >> l;

	for (int i = 0; i< m;i++) cin >> a[i];

	a[m] = l;
	while (n--) {
		int x; cin >> x;

		int lt = 1, rt = l;
		int ret = -1;
		while (lt <= rt) {
			// 작은 것 중 최대 길이가 mid
			int mid = (lt + rt) / 2;
			// 자를 수 있는 칸 중 앞에 칸을 잘랐을 때 mid보다 크거나 같으면 개수 늘림
			// 왜? 최대 길이를 구하며, x조각을 만들어야 함.
			// 최대 길이가 mid인 조각 개수가 적다 -> mid 길이를 줄이고 조각 개수를 늘린다.
			// mid인 조각 개수가 많다. mid보다 클 수도 있다.
			// mid인 조각 개수가 같거나 적다. mid가 작을 수 있다.
			if (cut(mid, x)) {
				rt = mid - 1;
			} else {
				lt = mid + 1;
				ret = max(ret, mid);
			}
		}
		cout << ret << endl;
	}
	return 0;
}