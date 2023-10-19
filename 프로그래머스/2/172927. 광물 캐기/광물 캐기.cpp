#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

unordered_map<string, int> m;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int piro[3][3] = {
        {1, 1, 1},
        {5, 1, 1},
        {25, 5, 1}
    };
    m["diamond"] = 0;
    m["iron"] = 1;
    m["stone"] = 2;
    
    vector<int> ord;
    
    for (int i = 0; i < picks.size();i++) {
        while (picks[i] != 0) {
            ord.push_back(i);
            picks[i]--;
        }
    }
    answer = 9999999;
    do {
        vector<string> tmp(minerals);
        int cur = 0;
        int piros = 0;
        for (int i = 0; i < ord.size();i++) {
            int j = cur;
            for (j; j < cur + 5 && j < tmp.size(); j++)
                piros += piro[ord[i]][m[tmp[j]]];
            
            if (j == tmp.size()) break;
            cur = j;
        }
        answer = min(piros, answer);
    } while (next_permutation(ord.begin(), ord.end()));
    
    return answer;
}