#include <string>
#include <iostream>
#include <vector>

using namespace std;

int nn, mm;
int sx, sy;

int getDistance(int x, int y) {
    int xDist = (x-sx);
    int yDist = (y-sy);
    
    return (xDist*xDist) + (yDist*yDist);
}

int getUpDist(int targetX, int targetY, int exclude) {
    if (exclude == 0) return 1e9;
    return getDistance(targetX, 2*nn - targetY);
}

int getDownDist(int targetX, int targetY, int exclude) {
    if (exclude == 1) return 1e9;
    return getDistance(targetX, targetY * -1);
}

int getLeftDist(int targetX, int targetY, int exclude) {
    if (exclude == 2) return 1e9;
    return getDistance(targetX * -1, targetY);
}

int getRightDist(int targetX, int targetY, int exclude) {
    if (exclude == 3) return 1e9;
    return getDistance(2*mm - targetX, targetY);
}

int getDist(int targetX, int targetY, int exclude) {
    int ans = 1e9;
    ans = min(getUpDist(targetX, targetY, exclude), ans);
    ans = min(getDownDist(targetX, targetY, exclude), ans);
    ans = min(getLeftDist(targetX, targetY, exclude), ans);
    ans = min(getRightDist(targetX, targetY, exclude), ans);
    
    return ans;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    nn = n; mm = m; sx = startX; sy = startY;
    
    // 각 축으로 ball을 뒤집는다.
    for (int i = 0; i < balls.size();i++) {
        int targetX = balls[i][0];
        int targetY = balls[i][1];
        int exclude = 5; // 모두 포함
        // 평행 또는 수직일 때 겹치는 경로는 제외한다.
        
        // 0,1,2,3 으로 상하좌우 구분하기
        if (startX == targetX) { // startY와 targetY의 차이를 통해 한 방향을 배제한다.
            if (startY < targetY) { // y축 즉, n 으로 뒤집지 않는다.위 X ; 왼쪽, 오른쪽, 아래
                exclude = 0;
            } else { // y축 0을 기준으로 뒤집지 않는다. 아래 X ; 왼쪽, 오른쪽, 위
                exclude = 1;
            }
        } else if (startY == targetY) { // startX와 targetX의 차이를 통해 한 방향을 배제한다.
            if (startX < targetX) { // x축 즉, m으로 뒤집지 않는다. 오른쪽 X ; 왼쪽, 위, 아래
                exclude = 3;
            } else { // x축 0을 기준으로 뒤집지 않는다. 왼쪽 X ; 오른쪽, 위, 아래
                exclude = 2;
            }
        }
        answer.push_back(getDist(targetX, targetY, exclude));
    }
    return answer;
}