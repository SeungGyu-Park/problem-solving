#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;
int arr[1001];
int dp[1001]; // dp[k]: k번째까지 오름차수의 순
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i<n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 0; i<n;i++){
        for (int j= 0; j<i;j++){
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp, dp+n);
    return 0;
}