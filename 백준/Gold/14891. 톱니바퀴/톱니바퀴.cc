#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define RIGHT 2
#define LEFT 6
#define N 0
#define S 1

int wheels[4][8];
bool wheelsTurn[4];

int inputK;

void input() {
    for (int i = 0; i < 4; i++) {
        string oneLine;
        cin >> oneLine;
        for (int j = 0; j < 8; j++) {
            wheels[i][j] = oneLine[j] - '0';
        }
    }

    cin >> inputK;
}

void initWheelsTurn() {
    for (int i = 0; i < 4; i++) {
        wheelsTurn[i] = false;
    }
}

bool isLeftWheelSpin(int wheelNum) {
    if (wheelNum == 0) return false;

    if (wheels[wheelNum - 1][RIGHT] != wheels[wheelNum][LEFT]) return true;

    return false;
}

bool isRightWheelSpin(int wheelNum) {
    if (wheelNum == 3) return false;

    if (wheels[wheelNum + 1][LEFT] != wheels[wheelNum][RIGHT]) return true;

    return false;
}

void moveWheels(int wheelNum, int dir) {
    if (wheelsTurn[wheelNum]) return;

    // 회전 하기 전 오른쪽 왼쪽 톱니바퀴 확인
    bool leftSpin = false;
    bool rightSpin = false;

    if (isLeftWheelSpin(wheelNum)) {
        leftSpin = true;
    } 

    if (isRightWheelSpin(wheelNum)) {
        rightSpin = true;
    }

    // 시계방향 회전
    if (dir == 1) {
        int last = wheels[wheelNum][7];

        for (int i = 7; i > 0; i--) {
            wheels[wheelNum][i] = wheels[wheelNum][i - 1];
        }

        wheels[wheelNum][0] = last;

    } else { // 반시계방향 회전
        int first = wheels[wheelNum][0];

        for (int i = 1; i < 8; i++) {
            wheels[wheelNum][i - 1] = wheels[wheelNum][i];
        }

        wheels[wheelNum][7] = first;
    }

    wheelsTurn[wheelNum] = true;

    if (leftSpin) moveWheels(wheelNum - 1, -dir);

    if (rightSpin) moveWheels(wheelNum + 1, -dir);

    return;
}

int getScore() {
    int score = 0;

    for (int i = 0 ;i < 4; i++) {
        if (wheels[i][0] == S) {
            score += (1 * pow(2, i));
        }
    }

    return score;
}

int main(void) {
    input();

    for (int i = 0; i < inputK; i++) {
        int num, dir;
        cin >> num >> dir;

        initWheelsTurn();
        moveWheels(num - 1, dir);
    }

    cout << getScore() << "\n";

    return 0;
}