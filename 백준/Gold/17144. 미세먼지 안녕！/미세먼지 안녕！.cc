#include <iostream>

using namespace std;

#define DIFFUSE_DIR_COUNT 4

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int inputR;
int inputC;
int inputT;

int airX;
int airOneY;
int airTwoY;

int board[51][51];
int temp[51][51];

void diffuse() {
    // 모든 칸의 미세먼지의 확산되는 양 계산
    for (int i = 0; i < inputR; i++) {
        for (int j = 0; j < inputC; j++) {
            if (board[i][j] == -1) continue;

            int originDust = board[i][j];
            int validDir = 0;

            // 사방에 확산가능한 칸이 있으면 주고 남은 값 저장
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny < 0 || ny >= inputR || nx < 0 || nx >= inputC) continue;

                if (board[ny][nx] == -1) continue;

                validDir++;
            }

            temp[i][j] = (board[i][j] - ((originDust / 5) * validDir));

            // 사방에서부터 확산받을 값이 있다면 받은 값 누적해서 저장
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny < 0 || ny >= inputR || nx < 0 || nx >= inputC) continue;

                if (board[ny][nx] == -1) continue;

                int diffuseAmount = board[ny][nx] / 5;

                temp[i][j] += diffuseAmount;
            }
        }
    }

    // 모든 칸 미세먼지 업데이트
    for (int i = 0; i < inputR; i++) {
        for (int j = 0; j < inputC; j++) {
            if (board[i][j] == -1) continue;
            board[i][j] = temp[i][j];
        }
    }
}

// airOne과 airTwo 기준으로 상하로 나누고 회전 시키기
void spin() {
    // airOne 반시계방향으로 회전
    
    // 1. 서쪽 세로 남쪽으로 한 칸씩 밀기
    for (int i = airOneY; i > 0; i--) {
        if (board[i][0] == -1) continue;
        board[i][0] = board[i - 1][0];
    }

    // 2. 북쪽 가로 서쪽으로 한 칸씩 밀기
    for (int j = 1; j < inputC; j++) {
        board[0][j - 1] = board[0][j];
    }

    // 3. 동쪽 세로 북쪽으로 한 칸씩 밀기
    for (int i = 1; i <= airOneY; i++) {
        board[i - 1][inputC - 1] = board[i][inputC - 1];
    }

    // 4. 남쪽 가로 동쪽으로 한 칸씩 밀기
    for (int j = inputC - 1; j > 0; j--) {
        if (board[airOneY][j - 1] == -1) {
            board[airOneY][j] = 0;
        } else {
            board[airOneY][j] = board[airOneY][j - 1];
        }
    }

    // airTwo 시계방향으로 회전

    // 1. 서쪽 세로 북쪽으로 한 칸씩 밀기
    for (int i = airTwoY + 1; i <= inputR; i++) {
        if (board[i - 1][0] == -1) continue;
        board[i - 1][0] = board[i][0];
    }

    // 2. 남쪽 가로 서쪽으로 한 칸씩 밀기
    for (int j = 1; j <= inputC; j++) {
        board[inputR - 1][j - 1] = board[inputR - 1][j];
    }

    // 3. 동쪽 세로 남쪽으로 한 칸씩 밀기
    for (int i = inputR - 1; i > airTwoY; i--) {
        board[i][inputC - 1] = board[i - 1][inputC - 1];
    }

    // 4. 북쪽 가로 동쪽으로 한 칸씩 밀기
    for (int j = inputC - 1; j > 0; j--) {
        if (board[airTwoY][j - 1] == -1) {
            board[airTwoY][j] = 0;
        } else {
            board[airTwoY][j] = board[airTwoY][j - 1];
        }
    }
}

int getDust() {
    int dust = 0;

    for (int i = 0; i < inputR; i++) {
        for (int j = 0; j < inputC; j++) {
            if (board[i][j] == -1) continue;
            dust += board[i][j];
        }
    }

    return dust;
}

int main(void) {
    cin >> inputR >> inputC >> inputT;

    for (int i = 0; i < inputR; i++) {
        for (int j = 0; j < inputC; j++) {
            cin >> board[i][j];

            if (board[i][j] == -1) {
                airTwoY = i;
            }
        }
    }

    // 마지막으로 저장된 공기청정기의 Y축이 아래이기 때문에 첫번째 y에 -1을 해준 값을 할당한다.
    airOneY = airTwoY - 1;

    // inputT만큼 확산과 회전 수행
    for (int t = 0; t < inputT; t++) {
        // 확산
        diffuse();
        // 회전
        spin();
    }

    // 미세먼지 양 세기
    cout << getDust() << "\n";

    return 0;
}