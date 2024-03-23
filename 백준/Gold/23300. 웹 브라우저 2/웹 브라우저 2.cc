#include <iostream>
#include <deque>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

deque<int> back, front;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int n, q;
	int cur = -1;
	cin >> n >> q;

	while (q--) {
		char cmd; cin >> cmd;
		
		if (cmd == 'A') {
			int x; cin >> x;

			front.clear();
			
			if (cur == -1) {
				cur = x; continue;
			}
			back.push_back(cur);
			cur = x;
		} else if (cmd == 'B') {
			if (back.empty() || cur == -1) continue;
			
			front.push_front(cur);
			cur = back.back();
			back.pop_back();
		} else if (cmd == 'C') {
			if (back.size() <= 1) continue;
			deque<int> tmp;
			int lt = 0, rt = 1;

			while (lt <= rt && rt <= back.size()) {

				while (back[lt] == back[rt]) rt++;
				if (rt - lt == 1) {
					tmp.push_back(back[lt]);
					lt++; rt++;
					continue;
				}
				tmp.push_back(back[rt-1]);
				lt = rt;
				rt = lt + 1;
			}
			back = tmp;
		} else if (cmd == 'F') {
			if (front.empty() || cur == -1) continue;
		
			back.push_back(cur);
			cur = front.front();
			front.pop_front();
		}
	}

	cout << cur << endl;

	if (back.empty()) cout << -1 << endl;
	else {
		reverse(back.begin(), back.end());
		for (auto e : back) cout << e << " ";
		cout << endl;
	}

	if (front.empty()) cout << -1 << endl;
	else {
		for (auto e : front) cout << e << " ";
		cout << endl;
	}

	return 0;
}