#include <string>
#include <iostream>
#include <map>
#include <vector>
#define endl "\n";
using namespace std;

map<string, int> m;
int solution(vector<string> babbling) {
    int answer = 0;
    string words[5] = {"", "aya", "ye", "woo", "ma"};
    
    for (int i = 1 ; i <= 4;i++) {
        m[words[i]] = i;
    }
    for (string str : babbling) {
        string tmp;
        int flag = 1;
        int prev = -1;
        int cur = -1;
        for (int i = 0; i < str.size();i++) {
            tmp += str[i];
            cur = m[tmp];
            if (m[tmp] && prev != cur) {
                prev = cur;
                tmp = "";
                flag = 0;
            } else flag = 1;
        }
        if (!flag) answer++;
    }
    return answer;
}