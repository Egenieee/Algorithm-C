#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define RIGHT 1
#define LEFT 2
#define APPLE 1

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int trans[10000];
int board[101][101];
vector<pair<int, int>> snakesPos;

int inputN;
int inputK;
int inputL;

int snakeHeadY;
int snakeHeadX;

int snakeDir;
int snakeLen;

int curTime;

// 머리 움직일 때 뱀의 위치 벡터에 새로 옮긴 위치를 넣어주자
void moveHead() {
    // 뱀 방향대로 한 칸 머리 이동
    snakeHeadY += dy[snakeDir];
    snakeHeadX += dx[snakeDir];
}

// 현재 머리 위치가 벽이나 몸 위치라면 true 아니면 false
bool isWallOrBody() {
    // 벽이면 true
    if (snakeHeadY < 0 || snakeHeadY >= inputN || snakeHeadX < 0 || snakeHeadX >= inputN) return true;

    // 모든 뱀 몸을 보면서 위치가 같다면 ture
    for (int i = 0; i < snakesPos.size(); i++) {
        int bodyY = snakesPos[i].first;
        int bodyX = snakesPos[i].second;

        if (bodyY == snakeHeadY && bodyX == snakeHeadX) return true;
    }

    return false;
}

// 뱀의 위치 벡터에서 꼬리 위치를 없앤다.
void moveTale() {
    // snakesPos.erase(find(snakesPos.begin(), snakesPos.end(), 0), snakesPos.end());
    snakesPos.erase(snakesPos.begin() + 0);
}

void spinToLeft() {
    // 왼쪽이면 - 1
    snakeDir--;

    if (snakeDir < 0) {
        snakeDir = 3;
    }
}

void spinToRight() {
    // 오른쪽이면 + 1
    snakeDir++;

    if (snakeDir > 3) {
        snakeDir = 0;
    }
}

// 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
// 만약 벽이나 자기자신의 몸과 부딪히면 게임이 끝난다.
// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
void solution() {
    while(true) {
        curTime++;
        
        // 뱀의 머리 이동 -> 뱀 몸 길이 늘어남
        moveHead();

        // 벽이나 자기자신의 몸과 만나면 게임 끝
        if (isWallOrBody()) {
            return;
        }

        // 뱀 머리 뱀 위치 벡터에 추가
        snakesPos.push_back({snakeHeadY, snakeHeadX});

        // 머리의 위치에 사과가 있다면, 사과 없어짐
        if (board[snakeHeadY][snakeHeadX] == APPLE) {
            board[snakeHeadY][snakeHeadX] = 0;
        } 
        
        // 머리의 위치에 사과가 없다면, 꼬리 위치 바꾸기
        else {
            moveTale();
        }

        if (trans[curTime] == LEFT) {
            spinToLeft();
        } else if (trans[curTime] == RIGHT) {
            spinToRight();
        }
    }
}

int main(void) {
    cin >> inputN >> inputK;

    for (int i = 0; i < inputK; i++) {
        int appleY, appleX;
        cin >> appleY >> appleX;

        board[appleY - 1][appleX - 1] = APPLE;
    }

    cin >> inputL;

    for (int i = 0; i < inputL; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        
        if (dir == 'L') {
            trans[time] = LEFT;
        } else {
            trans[time] = RIGHT;
        }
    }

    curTime = 0;
    snakeHeadY = 0;
    snakeHeadX = 0;
    snakesPos.push_back({snakeHeadY, snakeHeadX});

    solution();

    cout << curTime << "\n";

    return 0;
}