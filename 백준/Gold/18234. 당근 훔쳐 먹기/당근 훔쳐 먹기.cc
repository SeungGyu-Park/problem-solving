#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

ll w[200001], p[200001];

struct compare {

	bool operator() (pair<ll, ll> &a, pair<ll, ll> &b) {
	
		if (p[a.second] == p[b.second]) return a.first < b.first;
		return p[a.second] > p[b.second];
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	int n, t;

	cin >> n >> t;

	for (int i = 1; i <= n;i++) cin >> w[i] >> p[i];
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, compare> pq;
	for (ll i = 1; i<=n;i++){
		ll tmp = w[i] + (p[i] * (t-n));
		pq.push({tmp, i});
	}
	
	ll ans = 0;
	for (ll i = 1; i<=n;i++) {
		ll s, idx;
		tie(s,idx) = pq.top(); pq.pop();
		ans += s + p[idx] * (i-1);
	}
	cout << ans;
	return 0;
}