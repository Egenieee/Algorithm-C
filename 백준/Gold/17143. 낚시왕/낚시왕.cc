#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};

int inputR;
int inputC;
int inputM;

int kingX;

int totalCatch;

struct shark {
    int speed;
    int dir;
    int size;
};

shark sharks[101][101];
shark temp[101][101];

void catchShark() {
    for (int i = 1; i <= inputR; i++) {
        if (sharks[i][kingX].size > 0) {

            totalCatch += sharks[i][kingX].size;

            sharks[i][kingX].dir = 0;
            sharks[i][kingX].size = 0;
            sharks[i][kingX].speed = 0;

            inputM--;

            return;
        }
    }
}

void moveShark() {
    // 상어 하나하나 이동시키기
    for (int i = 0; i <= inputR; i++) {
        for (int j = 0; j <= inputC; j++) {
            if (sharks[i][j].dir == 0) continue;

            // 상어인 경우 이동시키기
            int movedX = j;
            int movedY = i;

            // 현재 이동한 상어
            shark curShark = sharks[i][j];

            int sharkSpeed = sharks[i][j].speed;

            if (sharks[i][j].dir == LEFT || sharks[i][j].dir == RIGHT) {

                while(sharkSpeed--) {
                    if (movedX == 1) {
                        curShark.dir = RIGHT;
                    } else if (movedX == inputC) {
                        curShark.dir = LEFT;
                    }

                    movedX += dx[curShark.dir];
                }

                // 이동할 위치에 이미 다른 상어가 있다면, 지금 상어와 비교해서 하나만 남기기
                if(temp[movedY][movedX].size < curShark.size) {
                    temp[movedY][movedX] = curShark;
                }
            } 
        
            else {
                while(sharkSpeed--) {
                    if (movedY == 1) {
                        curShark.dir = DOWN;
                    } else if (movedY == inputR) {
                        curShark.dir = UP;
                    }

                    movedY += dy[curShark.dir];
                }

                // 이동할 위치에 이미 다른 상어가 있다면, 지금 상어와 비교해서 하나만 남기기
                if(temp[movedY][movedX].size < curShark.size) {
                    temp[movedY][movedX] = curShark;
                }
            }
        }
    }

    for (int i = 0; i <= inputR; i++) {
        for (int j = 0; j <= inputC; j++) {
            sharks[i][j] = temp[i][j];
            temp[i][j] = {0, 0, 0};
        }
    }
}

int main(void) {
    cin >> inputR >> inputC >> inputM;

    for (int i = 0; i < inputM; i++) {
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        if (d == 1 || d == 2) s %= ((inputR - 1) * 2);   // 상어가 원래 자리로 돌아오는 경우,
        if (d == 3 || d == 4) s %= ((inputC - 1) * 2);   // 해당 부분은 빼고 최소 속도만 고려한다.

        sharks[r][c].speed = s;
        sharks[r][c].size = z;
        sharks[r][c].dir = d;
    }

    totalCatch = 0;
    kingX = 0;

    while(true) {
        // 낚시왕 이동
        kingX++;

        // 끝까지 도달했다면 끝
        if (kingX == inputC + 1) break;

        if (inputM == 0) break;

        // 상어 잡기
        catchShark();

        // 상어 이동
        moveShark();
    }

    cout << totalCatch << "\n";

    return 0;
}