#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int inputN;
int inputM;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int distFire[1001][1001];
int distSg[1001][1001];

int board[1001][1001];

int found;

void init() {
    found = 0;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            distFire[i][j] = -1;
            distSg[i][j] = -1;
            board[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        cin >> inputM >> inputN;

        init();

        queue<pair<int, int>> fireQ;
        queue<pair<int, int>> sgQ;

        for (int i = 0; i < inputN; i++) {
            string oneLine;
            cin >> oneLine;
            for (int j = 0; j < inputM; j++) {
                if (oneLine[j] == '#') {
                    board[i][j] = -1;
                } else if (oneLine[j] == '*') {
                    fireQ.push({i, j});
                    distFire[i][j] = 0;
                } else if (oneLine[j] == '@') {
                    sgQ.push({i, j});
                    distSg[i][j] = 0;
                }
            }
        }

        // 불 퍼뜨리기
        while(!fireQ.empty()) {
            int curY = fireQ.front().first;
            int curX = fireQ.front().second;
            fireQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];

                if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;
                if (board[ny][nx] == -1 || distFire[ny][nx] >= 0) continue;

                distFire[ny][nx] = distFire[curY][curX] + 1;
                fireQ.push({ny, nx});
            }
        }

        // 상근이 움직이기
        while(!sgQ.empty()) {
            if (found) break;
            int curY = sgQ.front().first;
            int curX = sgQ.front().second;
            sgQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];

                if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) {
                    cout << distSg[curY][curX] + 1 << "\n";
                    found = 1;
                    break;
                }
                if (board[ny][nx] == -1 || distSg[ny][nx] >= 0) continue;
                if (distFire[ny][nx] != -1 && distFire[ny][nx] <= distSg[curY][curX] + 1) continue;

                distSg[ny][nx] = distSg[curY][curX] + 1;
                sgQ.push({ny, nx});
            }
        }

        if (!found) {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}