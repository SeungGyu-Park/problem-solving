#include <iostream>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    int arr[1001];
    int dp[1001];

    cin >> n;
    for(int i =0 ; i< n;i++)
        cin >> arr[i];
    sort(arr, arr + n);
    dp[0] = arr[0];
    for (int i = 1; i< n;i++) 
        dp[i] = dp[i-1] + arr[i];
    int ans = 0;
    for (int i = 0; i < n;i++)
        ans += dp[i];
    cout << ans << endl;    
    return 0;
}