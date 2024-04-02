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

	for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); ++it) {
		sort(it->second.begin(), it->second.end());
	}


	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); ++i) {
		for (map<int, vector<int>>::iterator j = next(i); j != m.end(); ++j) {
			
			vector<int> x1 = i->second;
			vector<int> x2 = j->second;

			vector<int> cnt;
			int p1 = 0, p2 = 0;
			while (p1 < x1.size() && p2 < x2.size()) {

				if (x1[p1] == x2[p2]) {
					cnt.push_back(x1[p1]);
					++p1; ++p2;
				} else if (x1[p1] < x2[p2]) {
					++p1;
				} else ++p2;
			}
			rec += (cnt.size() * (cnt.size() -1))/2;
		}
	}
	cout << rec;
	return 0;
}