#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int> m;
int solution(vector<string> babbling) {
    int answer = 0;
    string words[4] = {"aya", "ye", "woo", "ma"};
    
    for (auto w : words) {
        m[w]++;
    }
    
    for (auto str : babbling) {
        
        string tmp;
        int flag = 1;
        for (auto c : str) {
            tmp += c;
            if (m[tmp]) {
                tmp = "";
                flag = 0;
            } else flag = 1;
        }
        if (!flag) answer++;
    }
    return answer;
}