#include <iostream>
#include <queue>

using namespace std;

int board[51][51];
bool cleaned[51][51];

// 북, 동, 남, 서 방향
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int inputN;
int inputM;

int robotY;
int robotX;

int robotDir;

int cleanRoom;

// 현재 칸의 주변 4칸 중(벽 포함) 청소되지 않은 칸이 하나라도 있으면 false, 모두 깨끗하면 true
bool isAllClean() {
    for (int dir = 0; dir < 4; dir++) {
        int ny = robotY + dy[dir];
        int nx = robotX + dx[dir];

        if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM || board[ny][nx] == 1) continue;

        if (!cleaned[ny][nx]) return false;
    }

    return true;
}

int getReverseDir() {
    int reverseDir;
    
    if (robotDir >= 2) {
        reverseDir = robotDir - 2;
    } else {
        reverseDir = robotDir + 2;
    }

    return reverseDir;
}

// 후진할 수 있는 경우인지 확인 
// 바라보는 방향의 뒤쪽 칸이 벽인지 확인
bool canReverse() {
    int reverseDir = getReverseDir();

    int ny = robotY + dy[reverseDir];
    int nx = robotX + dx[reverseDir];

    if (board[ny][nx] == 1) return false;

    return true;
}

void reverseRobot() {
    int reverseDir = getReverseDir();

    robotY = robotY + dy[reverseDir];
    robotX = robotX + dx[reverseDir];
}

void spinDir() {
    robotDir--;

    if (robotDir < 0) {
        robotDir = 3;
    }
}

void moveRobot() {
    robotY = robotY + dy[robotDir];
    robotX = robotX + dx[robotDir];
}

bool isDirtyForward() {
    int ny = robotY + dy[robotDir];
    int nx = robotX + dx[robotDir];

    if (cleaned[ny][nx] || board[ny][nx] == 1) return false;

    return true;
}

int main(void) {
    cin >> inputN >> inputM >> robotY >> robotX >> robotDir;

    cleanRoom = 0;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            cin >> board[i][j];
            cleaned[i][j] = false;
        }
    }

    while(true) {
        // 현재 칸이 청소되지 않은 경우, 현재 칸을 청소한다.
        if (!cleaned[robotY][robotX]) {
            cleaned[robotY][robotX] = true;
            cleanRoom++;
        }

        // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        // 현재 칸의 주변 4칸 중 벽 포함 모두 청소되었거나 
        if (isAllClean()) {
            if (canReverse()) {
                reverseRobot();
                continue;
            } else {
                break;
            }
        }

        // 현재 칸의 주변 4칸 중 청소되니 않은 빈 칸이 있는 경우
        else {
            // 반 시계 방향으로 회전한다
            spinDir();

            // 앞 칸이 청소되지 않은 칸이라면 한 칸 전진
            if (isDirtyForward()) {
                moveRobot();
            }
        }
    }

    cout << cleanRoom << "\n";

    return 0;
}