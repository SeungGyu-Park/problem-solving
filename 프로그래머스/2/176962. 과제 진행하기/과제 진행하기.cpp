#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    if (a[1] > b[1]) return 0;
    return 1;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), cmp);
    
    vector<pair<string, pair<int, int>>> p;
    
    stack<pair<string, pair<int, int>>> hold;
    for (int i = 0; i < plans.size();i++) {
        string str = plans[i][0];
        int start = stoi(plans[i][1].substr(0, 2)) * 60 + stoi(plans[i][1].substr(3, 5));
        int payTime = stoi(plans[i][2]);
        cout << str << " " << start << " " << payTime << "\n";
        p.push_back({str, {start, payTime}});
    }
    
    for (int i = 0; i < p.size()-1;i++) {
        pair<string, pair<int, int>> cur = p[i];
        pair<string, pair<int, int>> next = p[i+1];
        
        int curTime = cur.second.first;
        int curPayTime = cur.second.second;
        
        int nextTime = next.second.first;
        int nextPayTime = next.second.second;
        
        // 현재 과제를 다음 과제 전까지 마칠 때.
        // 스택의 못 마쳤던 과제를 할 수 있다. 근데 다음 과제 까지의 시간을 계산해야한다.
        if (curTime + curPayTime <= nextTime) {
            // 일단 마쳤으니까 답에 추가한다.
            answer.push_back(cur.first);
            // 끝나는 시간을 저장한다.
            int endTime = curTime + curPayTime;
            if (endTime == nextTime) continue;
            // 못 마쳤던 과제 중 끝나는 시간endTime + 남은 걸리는 시간holdPayTime이 nextTime 전이면 계속한다.
            while (!hold.empty()) {
                pair<string, pair<int, int>> holdOne = hold.top();
                hold.pop();
                int holdTime = holdOne.second.first;
                int holdPayTime = holdOne.second.second;
                
                // 다음 과제 전 까지 마칠 수 있으면 과제를 답에 추가한다.
                if (endTime + holdPayTime <= nextTime) {
                    answer.push_back(holdOne.first);
                    // 이제 과제를 마쳤으니 끝나는 시간을 더 저장한다.
                    endTime += holdPayTime;
                    if (endTime == nextTime) break;
                } else {
                    cout << holdOne.first << "\n";
                    hold.push({holdOne.first, {endTime + holdPayTime, endTime + holdPayTime - nextTime}});
                    break;
                }
            }
        } else { // 못 마친다 -> 현재 과제 걸리는 시간이 길다 -> 다음 과제 시간까지 하고 남은 걸리는 시간을 스택에 넣는다.
            hold.push({cur.first, {nextTime, curTime + curPayTime - nextTime}});
        }
    }
    answer.push_back(p[p.size()-1].first);
    while (!hold.empty()) {
        answer.push_back(hold.top().first);
        hold.pop();
    }
    return answer;
}