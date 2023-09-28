#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int inputN;
int inputM;
int maxArea;

int board[8][8]; // 원래 연구소 나타낼 보드
int temp[8][8]; // 매번 바이러스가 모두 퍼져나간 뒤의 연구소 구할 때 사용하는 보드


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> virusPos;

void getSafeArea() {
    queue<pair<int, int>> queue;

    for (pair<int, int> point : virusPos) {
        queue.push(point);
    }

    int area = 0;

    while(!queue.empty()) {
        pair<int, int> pos = queue.front();
        queue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = pos.first + dx[dir];
            int ny = pos.second + dy[dir];

            if (nx < 0 || nx >= inputN || ny < 0 || ny >= inputM) continue;

            if (temp[nx][ny] == 1 || temp[nx][ny] == 2) continue;

            queue.push({nx, ny});
            temp[nx][ny] = 2;
        }
    }

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            if (temp[i][j] == 0) {
                area++;
            }
        }
    }

    maxArea = max(area, maxArea);
}

void initBoard() {
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            // 벽만 냅두고 나머지 원래 보드 모양이랑 같도록 원복
            if (temp[i][j] != 1) {
                temp[i][j] = board[i][j];
            }
        }
    }
}

// 전에 설치한 벽의 y, x 좌표와 지금까지 설치한 벽의 개수 count
void dfs(int count, int y, int x) {
    // 3개 벽을 모두 세웠다면, 안전지대 면적 구한 뒤, 다시 temp 보드 원복
    if (count == 3) {
        getSafeArea();
        initBoard();
        return;
    }

    // x좌표만 움직이며 벽 설치

    for (int i = y; i < inputN; i++) {
        // 바로 이전에 설치한 벽의 x좌표 + 1 값 그대로 j에 할당 -> 이전에 설치한 x좌표 다음부터 살펴보기
        int j = x;

        // 바로 이전에 설치한 벽의 y 좌표와 현재 보고 있는 y축이 달라졌다면, j는 0부터 탐색
        if (i != y) {
            j = 0;
        }

        for (; j < inputM; j++) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                dfs(count + 1, i, j + 1);
                temp[i][j] = 0;
            }
        }
    }
}

int main(void) {
    cin >> inputN >> inputM;
    maxArea = -1;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            cin >> board[i][j];

            temp[i][j] = board[i][j];

            if (board[i][j] == 2) {
                virusPos.push_back({i, j});
            }
        }
    }

    dfs(0, 0, 0);

    cout << maxArea << "\n";

    return 0;
}