#include <string>
#include <iostream>
#include <vector>

using namespace std;

double getHourAngle(int hh, int mm, int ss) {

    double angle = 0.0;
    double h = hh*1.0;
    double m = mm * 1.0;
    double s = ss * 1.0;
    h *= 1.0, m *= 1.0, s *= 1.0;
    if (h >= 12.0) h -= 12.0;
    angle += h * 30.0;
    angle += m * 0.5;
    double tmp = s / 120;
    angle += tmp;
    if (angle != 0) return angle * 1.0;
    return 360.0;
}

double getMinuteAngle(int mm, int ss) {
    
    double angle = 0.0;
    
    double m = mm * 1.0;
    double s = ss * 1.0;
    
    m *= 1.0, s *= 1.0;
    angle += m * 6;
    angle += s * 0.1;
    if (angle == 0) angle = 360;
    return angle;
}

double getSecondAngle(double s) {
    if (s == 0) return 360;
    return s * 6;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    cout << getHourAngle(h1, m1, s1) << "\n";
    cout << getMinuteAngle(m1, s1) << "\n";
    cout << getSecondAngle(s1) << "\n";
    cout << "\n";
    cout << getHourAngle(h2, m2, s2) << "\n";
    cout << getMinuteAngle(m2, s2) << "\n";
    cout << getSecondAngle(s2) << "\n";
    
    cout << "\n";
    int st = h1 * 3600 + m1 * 60 + s1;
    int en = h2 * 3600 + m2 * 60 + s2;
    cout << st << " " << en << "\n";
    
    int hPrev = h1;
    int mPrev = m1;
    int sPrev = s1;
    double hourPrevAngle = getHourAngle(h1, m1, s1);
    double mimutePrevAngle = getMinuteAngle(m1, s1);
    double secondPrevAngle = getSecondAngle(s1);
    if (h1 == h2 && m1 == m2 && s1 == s2) return 1;
    if (hourPrevAngle == secondPrevAngle || mimutePrevAngle == secondPrevAngle) answer++;
    for (int t = st+1; t <=en; t++) {
        int tmp = t;
        int hCur = tmp / 3600;
        tmp %= 3600;
        int mCur = tmp / 60;
        tmp %= 60;
        int sCur = tmp;
        
        double prevHourAngle = getHourAngle(hPrev, mPrev, sPrev);
        double prevMinuteAngle = getMinuteAngle(mPrev, sPrev);
        double prevSecondAngle = getSecondAngle(sPrev);
        
        if (prevHourAngle == 360) prevHourAngle = 0;
        if (prevMinuteAngle == 360) prevMinuteAngle = 0;
        if (prevSecondAngle == 360) prevSecondAngle = 0;
        
        double curHourAngle = getHourAngle(hCur, mCur, sCur);
        double curMinuteAngle = getMinuteAngle(mCur, sCur);
        double curSecondAngle = getSecondAngle(sCur);
        
        if (curSecondAngle == curHourAngle && curSecondAngle == curMinuteAngle) answer++;
        else if (curSecondAngle == curHourAngle) answer++;
        else if (curSecondAngle == curMinuteAngle) answer++;
        if (prevSecondAngle < prevHourAngle && curHourAngle < curSecondAngle) {
            answer++;
        }
        if (prevSecondAngle < prevMinuteAngle && curMinuteAngle < curSecondAngle) {
            answer++;
        }
        
        hPrev = hCur;
        mPrev = mCur;
        sPrev = sCur;
    }
    return answer;
}