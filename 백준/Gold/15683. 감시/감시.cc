#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 동, 서, 남, 북
struct cctv {
    int right;
    int left;
    int down;
    int up;
};

struct cctvPos {
    int y;
    int x;
    int type;
};

struct selectedCctv {
    int y;
    int x;
    int type; // cctv 번호
    int posNum; // 감시 방향
};

int inputN, inputM;
int cctvCnt;
int board[10][10];
int minArea;

vector<cctv> cctvs[6];
vector<cctvPos> pos;
vector<selectedCctv> selected;

void init() {
    minArea = INT32_MAX;

    cctvs[1].push_back({1, 0, 0, 0});
    cctvs[1].push_back({0, 1, 0, 0});
    cctvs[1].push_back({0, 0, 1, 0});
    cctvs[1].push_back({0, 0, 0, 1});
    cctvs[2].push_back({1, 1, 0, 0});
    cctvs[2].push_back({0, 0, 1, 1});
    cctvs[3].push_back({1, 0, 0, 1});
    cctvs[3].push_back({1, 0, 1, 0});
    cctvs[3].push_back({0, 1, 1, 0});
    cctvs[3].push_back({0, 1, 0, 1});
    cctvs[4].push_back({1, 1, 0, 1});
    cctvs[4].push_back({1, 0, 1, 1});
    cctvs[4].push_back({1, 1, 1, 0});
    cctvs[4].push_back({0, 1, 1, 1});
    cctvs[5].push_back({1, 1, 1, 1});
}

// 현재 선택된 cctv로 영역 크기 구하기
void getArea() {
    for (selectedCctv each : selected) {
        cctv one = cctvs[each.type][each.posNum];
        
        // 동쪽으로 이동
        if (one.right) {
            for (int i = 1; i < inputM; i++) {
                int nx = each.x + i;

                if (board[each.y][nx] == 6 || nx >= inputM) break;

                if (board[each.y][nx] == 0) {
                    board[each.y][nx] = -1;
                }
            }
        }

        // 서쪽으로 이동
        if (one.left) {
            for (int i = 1; i < inputM; i++) {
                int nx = each.x - i;

                if (board[each.y][nx] == 6 || nx < 0) break;

                if (board[each.y][nx] == 0) {
                    board[each.y][nx] = -1;
                }
            }
        }

        // 남쪽으로 이동
        if (one.down) {
            for (int i = 1; i < inputN; i++) {
                int ny = each.y + i;

                if (board[ny][each.x] == 6 || ny >= inputN) break;

                if (board[ny][each.x] == 0) {
                    board[ny][each.x] = -1;
                }
            }
        }

        // 북쪽으로 이동
        if (one.up) {
            for (int i = 1; i < inputN; i++) {
                int ny = each.y - i;

                if (board[ny][each.x] == 6 || ny < 0) break;

                if (board[ny][each.x] == 0) {
                    board[ny][each.x] = -1;
                }
            }
        }
    }

    int cnt = 0;

    // 사각지대 구하기
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            if (board[i][j] == 0) {
                cnt++;
            }
        }
    }

    // board 원복
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
            }
        }
    }

    minArea = min(minArea, cnt);
}

void dfs(int curCnt) {
    if (curCnt == cctvCnt) {
        getArea();
        return;
    }

    cctvPos curCctvPos = pos[curCnt];
    
    for (int i = 0; i < cctvs[curCctvPos.type].size(); i++) {
        selected.push_back({curCctvPos.y, curCctvPos.x, curCctvPos.type, i});
        dfs(curCnt + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        for (int j= 0; j < inputM; j++) {
            cin >> board[i][j];

            if (board[i][j] >= 1 && board[i][j] != 6) {
                cctvCnt++;
                pos.push_back({i, j, board[i][j]});
            }
        }
    }

    init();
    dfs(0);
    
    cout << minArea;

    return 0;
}