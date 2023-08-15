#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int root) {
	cout << char(root + 'A' -1);
	if (lc[root] != 0) preorder(lc[root]);
	if (rc[root] != 0) preorder(rc[root]);
}
void postorder(int root) {
	if (lc[root] != 0) postorder(lc[root]);
	if (rc[root] != 0) postorder(rc[root]);
	cout << char(root + 'A' -1);
}
void inorder(int root) {
	if (lc[root] != 0) inorder(lc[root]);
	cout << char(root + 'A' -1);
	if (rc[root] != 0) inorder(rc[root]);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i<n;i++){
		char c, l, r;
		cin >> c >> l >> r;
		if (l != '.') lc[c-'A' + 1] = l - 'A' + 1;
		if (r != '.') rc[c-'A' + 1] = r - 'A' + 1;
	}
	preorder(1); cout << endl;
	inorder(1); cout << endl;
	postorder(1); cout << endl;
	return 0;
}