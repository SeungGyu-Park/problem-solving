#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n";
using namespace std;

vector<long long> sqq;

pair<long long,long long> count(long long r) {
    long long sum = 0;
    long long above_circle = 0;
    for (long long i = 1; i <= r - 1; i++) {
        long long tmp = r * r - i * i;
        
        long long idx2 = lower_bound(sqq.begin(), sqq.end(), tmp) - sqq.begin();
        
        if (idx2 * idx2 != tmp) idx2--;
        else above_circle++;
        sum += idx2;
    }
    return {sum * 4 + r * 4 + 1, above_circle * 4};
}

long long solution(int r1, int r2) {
    
    sqq.push_back(0);
    for (long long i = 1; i <= r2; i++) {
        sqq.push_back(i*i);
    }
    
    long long r1c, r1a, r2c, r2a;
    tie(r1c, r1a) = count(r1);
    tie(r2c, r2a) = count(r2);
    return r2c - r1c + r1a + 4;
}