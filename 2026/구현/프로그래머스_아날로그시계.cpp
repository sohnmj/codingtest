#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 특정 초(second) 일 때 각 침의 각도를 구하는 함수
// 오차를 방지하기 위해 각도 계산 시 double 자료형을 사용합니다.
double getHourAngle(int total_second) {
    // 시침은 1초에 1/120도 움직임. 12시간(43200초) 주기로 리셋
    return (total_second % 43200) * (1.0 / 120.0);
}

double getMinuteAngle(int total_second) {
    // 분침은 1초에 0.1(1/10)도 움직임. 1시간(3600초) 주기로 리셋
    return (total_second % 3600) * (1.0 / 10.0);
}

double getSecondAngle(int total_second) {
    // 초침은 1초에 6도 움직임. 1분(60초) 주기로 리셋
    return (total_second % 60) * 6.0;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    // 시작 시간과 종료 시간을 전부 초 단위로 환산
    int startTime = h1 * 3600 + m1 * 60 + s1;
    int endTime = h2 * 3600 + m2 * 60 + s2;

    // 1. 시작 시점에 이미 겹쳐 있는 경우 초기 카운트 설정
    // 0시 0분 0초 혹은 12시 0분 0초에는 세 침이 모두 겹치므로 알람이 1번만 울림
    if (startTime == 0 || startTime == 12 * 3600) {
        answer++;
    }
    else {
        // 그 외의 경우 시작 시점에 초침이 시침이나 분침과 일치하면 카운트
        if (getSecondAngle(startTime) == getHourAngle(startTime)) answer++;
        if (getSecondAngle(startTime) == getMinuteAngle(startTime)) answer++;
    }

    // 2. 1초씩 진행하며 진행되는 과정(t ~ t+1) 속에 만나는지 확인
    for (int t = startTime; t < endTime; ++t) {
        double curHour = getHourAngle(t);
        double curMin = getMinuteAngle(t);
        double curSec = getSecondAngle(t);

        double nextHour = getHourAngle(t + 1);
        double nextMin = getMinuteAngle(t + 1);
        double nextSec = getSecondAngle(t + 1);

        // 다음 위치가 0도(360도)로 리셋되는 경우, 이전 위치와의 비교를 위해 360도로 보정
        if (nextHour == 0) nextHour = 360.0;
        if (nextMin == 0) nextMin = 360.0;
        if (nextSec == 0) nextSec = 360.0;

        bool matchHour = false;
        bool matchMin = false;

        // 초침이 시침을 추월했거나, t+1 시점에 정확히 일치하는지 확인
        if (curSec < curHour && nextSec >= nextHour) {
            matchHour = true;
        }
        // 초침이 분침을 추월했거나, t+1 시점에 정확히 일치하는지 확인
        if (curSec < curMin && nextSec >= nextMin) {
            matchMin = true;
        }

        if (matchHour && matchMin) {
            // 시침과 분침을 둘 다 만났을 때
            // 만약 t+1 시점에 시침과 분침의 각도가 같다면 세 침이 한 곳에서 만난 것이므로 +1
            if (nextHour == nextMin) {
                answer += 1;
            }
            else {
                // 각각 다른 위치에서 만난 것이라면 +2
                answer += 2;
            }
        }
        else if (matchHour || matchMin) {
            // 둘 중 하나만 만났다면 +1
            answer += 1;
        }
    }

    return answer;
}
int main() {
    vector<vector<int>> a = {
    {1, 1},
    {1, 3}
    };

    vector<vector<int>> b = {
        {1, 2, 1, 2},
        {2, 1, 2, 1}
    };

    cout<<solution(a,b);
    

}