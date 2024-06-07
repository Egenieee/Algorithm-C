#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Wall {
    int y;
    int x;
    int isBroken;
};

int inputN;
int inputM;

int board[1001][1001];
int dist[1001][1001][2];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void init() {
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = -1;
            }
        }
    }
}

void bfs() {
    init();

    queue<Wall> myQ;
    dist[0][0][0] = 1;
    myQ.push({0, 0, 0});

    while(!myQ.empty()) {
        int curY = myQ.front().y;
        int curX = myQ.front().x;
        int isBroken = myQ.front().isBroken;
        myQ.pop();

        if (curY == inputN - 1 && curX == inputM - 1) {
            cout << dist[curY][curX][isBroken];
            return;
        }

        for (int dir = 0; dir < 4; dir++){
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;

            // 벽이 있고 벽을 아직 부수지 않은 경우 -> 벽을 부순다.
            if (board[ny][nx] == 1 && isBroken == 0) {
                dist[ny][nx][1] = dist[curY][curX][isBroken] + 1;
                myQ.push({ny, nx, 1});
            }

            // 벽이 없고 아직 방문하지 않은 곳이라면
            if (board[ny][nx] == 0 && dist[ny][nx][isBroken] < 0) {
                dist[ny][nx][isBroken] = dist[curY][curX][isBroken] + 1;
                myQ.push({ny, nx, isBroken});
            }
        }
    }

    cout << -1;
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        string oneLine;
        cin >> oneLine;
        for (int j = 0; j < inputM; j++) {
            board[i][j] = oneLine[j] - '0';
        }
    }

    bfs();

    return 0;
}