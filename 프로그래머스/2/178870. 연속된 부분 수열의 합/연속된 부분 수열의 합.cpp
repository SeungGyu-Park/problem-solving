#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dp[1000001];

vector<int> solution(vector<int> s, int k) {
    vector<int> answer;
    
    dp[0] = 0;
    for (int i = 0; i < s.size(); i++)
        dp[i+1] = dp[i] + s[i];
    
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i <= s.size(); i++) {
        int t = dp[i] - k;
        if (t < 0) continue;
        
        int idx = lower_bound(dp, dp + i, t) - dp;
        if (dp[i] - dp[idx] != k) continue;
        v.push_back({i - idx, {idx+1, i}});
    }
    sort(v.begin(), v.end());
    answer.push_back(v[0].second.first-1);
    answer.push_back(v[0].second.second-1);
    return answer;
}