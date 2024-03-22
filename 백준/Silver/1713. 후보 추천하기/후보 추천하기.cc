#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

struct cand {
	int id;
	int count;
	int time;
};

int n, k;
vector<cand> c;

bool cmp(const cand &a, const cand &b) {
	if (a.count == b.count) return a.time > b.time;
	return a.count < b.count;
}

bool ord(cand &a, cand &b) {
	return a.id < b.id;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n >> k;

	while (k--) {
		int r; cin >> r;

		bool flag = false;
		for (cand &e : c) {
			if (e.id == r) {
				e.count++;
				flag = true;
			}
			e.time++;
		}

		if (flag) continue; 
		if (c.size() == n) {
			auto leastVoted = min_element(c.begin(), c.end(), cmp);
			*leastVoted = {r, 1, 1};
			continue;
		};
		
		c.push_back({r, 1, 1});
	}

	sort(c.begin(), c.end(), ord);

	for (cand &e : c) {
		cout << e.id << " ";
	}
	return 0;
}