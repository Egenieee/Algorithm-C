#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct info {
    int y;
    int x;
};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int inputN, inputM;

int jihoonY;
int jihoonX;
int fireY;
int fireX;

int board[1001][1001];
int distJihoon[1001][1001];
int distFire[1001][1001];

queue<info> fireQ;
queue<info> jihoonQ;

void init() {
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            distJihoon[i][j] = -1;
            distFire[i][j] = -1;
        }
    }
}

void bfsFire() {
    while(!fireQ.empty()) {
        int curY = fireQ.front().y;
        int curX = fireQ.front().x;
        fireQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if (ny < 0  || ny >= inputN || nx < 0 || nx >= inputM) continue;
            if (distFire[ny][nx] >= 0 || board[ny][nx] == -1) continue;

            distFire[ny][nx] = distFire[curY][curX] + 1;
            fireQ.push({ny, nx});
        }
    }
}

void bfsJihoon() {
    while(!jihoonQ.empty()) {
        int curY = jihoonQ.front().y;
        int curX = jihoonQ.front().x;
        jihoonQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            // 범위 벗어났다면 탈출 성공이니 바로 리턴
            // BFS는 시간 순으로 큐에 들어가니까 탈출하면 바로 답임
            if (ny < 0  || ny >= inputN || nx < 0 || nx >= inputM) {
                cout << distJihoon[curY][curX] + 1;
                return;
            }

            if (distJihoon[ny][nx] >= 0 || board[ny][nx] == -1) continue;

            // 불이 해당 칸에 이미 번졌을 경우 못간다.
            // 벽인 경우는 제외
            if (distFire[ny][nx] != -1 && distFire[ny][nx] <= distJihoon[curY][curX] + 1) continue;

            distJihoon[ny][nx] = distJihoon[curY][curX] + 1;
            jihoonQ.push({ny, nx});
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    cin >> inputN >> inputM;

    init();

    for (int i = 0; i < inputN; i++) {
        string oneLine;
        cin >> oneLine;
        for (int j = 0; j < inputM; j++) {
            if (oneLine[j] == '#') {
                board[i][j] = -1;
            } else if (oneLine[j] == 'J') {
                distJihoon[i][j] = 0;
                jihoonQ.push({i, j});
            } else if (oneLine[j] == 'F') {
                distFire[i][j] = 0;
                fireQ.push({i, j});
            }
        }
    }
    
    bfsFire();
    bfsJihoon();
    
    return 0;
}