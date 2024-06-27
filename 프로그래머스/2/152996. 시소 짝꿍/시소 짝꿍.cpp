#include <string>
#include <set>
#include <vector>

using namespace std;

long long cnts[2001];

long long same(long long n) {
    long long res = 0;
    while (--n) res += n;
    return res;
}

long long solution(vector<int> w) {
    long long answer = 0;
    set<int> s;
    for (auto& e : w) {
        cnts[e]++;
        s.insert(e);
    }
    
    for (auto e : s) {
        answer += same(cnts[e]);
        if ((e * 4) % 3 == 0) answer += cnts[e] * cnts[(e * 4) / 3];
        if ((e * 4) % 2 == 0) answer += cnts[e] * cnts[(e * 4) / 2];
        if ((e * 3) % 2 == 0) answer += cnts[e] * cnts[(e * 3) / 2];
    }
    return answer;
}