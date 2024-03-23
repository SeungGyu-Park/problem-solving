#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1000000;
int dist[MAX + 1];

int solution(int x, int y, int n) {
    
    fill(dist, dist + MAX + 1, -1);
    
    queue<int> q;
    
    q.push(x);
    dist[x] = 0;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur > MAX || cur > y) return dist[y];
        
        for (int e : {cur + n,cur * 2, cur * 3}) {
            
            if (e > y) continue;
            if (dist[e] != -1) continue;
            
            dist[e] = dist[cur] + 1;
            q.push(e);
        }
    }
    return dist[y];
}