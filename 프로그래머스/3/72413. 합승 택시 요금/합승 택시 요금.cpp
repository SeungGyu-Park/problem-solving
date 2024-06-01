#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<pair<int, int>> g[201];

vector<int> dik(int n, int st) {
    vector<int> d(n+1, 1e9);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    d[st] = 0;
    pq.push({0, st});
    
    while (!pq.empty()) {
        int cost, vertex, nxt_cost, nxt_vertex;
        tie(cost, vertex) = pq.top(); pq.pop();
        
        for (pair<int, int>& e : g[vertex]) {
            tie(nxt_cost, nxt_vertex) = e;
            
            if (nxt_cost + d[vertex] >= d[nxt_vertex]) continue;
            d[nxt_vertex] = nxt_cost + d[vertex];
            pq.push({d[nxt_vertex], nxt_vertex});
        }
    }
    return d;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for (vector<int>& e : fares) {
        int u = e[0], v = e[1], w = e[2];
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    
    vector<int> ss = dik(n, s);
    vector<int> aa = dik(n, a);
    vector<int> bb = dik(n, b);
    
    int fare = INF;
    for (int i = 1; i <= n;i++) {
        if (ss[i] == INF || aa[i] == INF || bb[i] == INF) continue;
        fare = min(fare, (ss[i] + aa[i] + bb[i]));
    }
    return fare;
}