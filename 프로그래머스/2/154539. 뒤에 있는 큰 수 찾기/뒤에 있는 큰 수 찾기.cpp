#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> stk;
    
    for (int i = numbers.size() -1 ; i >= 0; i--) {
        while (!stk.empty() && numbers[i] >= stk.top())
            stk.pop();
        if (stk.empty()) answer.push_back(-1);
        else answer.push_back(stk.top());
        stk.push(numbers[i]);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}