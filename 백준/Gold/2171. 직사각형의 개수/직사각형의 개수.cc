#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int n;
map<int, vector<int>> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int n;
	ll rec = 0;

	cin >> n;

	for (int i = 0; i < n;i++) {
		int x, y;

		cin >> x >> y;
		m[x].push_back(y);
	}

	for (auto it = m.begin(); it != m.end(); ++it)
		sort(it->second.begin(), it->second.end());


	for (auto i = m.begin(); i != m.end(); ++i) {
		for (auto j = next(i); j != m.end(); ++j) {
			
			vector<int> cnt;
			set_intersection(i->second.begin(), i->second.end(), j->second.begin(), j->second.end(), back_inserter(cnt));
			rec += (cnt.size() * (cnt.size() -1))/2;
		}
	}
	cout << rec;
	return 0;
}