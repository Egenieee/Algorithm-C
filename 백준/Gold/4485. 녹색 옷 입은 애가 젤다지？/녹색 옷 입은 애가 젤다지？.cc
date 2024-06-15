#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

struct pos {
    int y;
    int x;
    int cost;
};

struct compare {
    bool operator()(pos one, pos two) {
        return one.cost > two.cost;
    }
};

int inputN;
int dist[150][150];
int board[150][150];

void init() {
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            dist[i][j] = INT32_MAX;
        }
    }
}

void dijkstra() {
    priority_queue<pos, vector<pos>, compare> myQ;

    init();
    dist[0][0] = board[0][0];
    myQ.push({0, 0, dist[0][0]});

    while(!myQ.empty()) {
        int curY = myQ.top().y;
        int curX = myQ.top().x;
        int curCost = myQ.top().cost;
        myQ.pop();

        if (dist[curY][curX] < curCost) continue;

        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            int nCost = board[ny][nx];

            if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputN) continue;

            if (dist[ny][nx] > dist[curY][curX] + nCost) {
                dist[ny][nx] = dist[curY][curX] + nCost;
                myQ.push({ny, nx, dist[ny][nx]});
            }
        }
    }
}

int main() {
    int testCase = 1;

    while(true) {
        cin >> inputN;

        if (inputN == 0) break;

        for (int i = 0; i < inputN; i++) {
            for (int j = 0; j < inputN; j++) {
                cin >> board[i][j];
            }
        }

        dijkstra();

        cout << "Problem " << testCase++ << ": " << dist[inputN - 1][inputN - 1] << "\n";
    }

    return 0;
}