#include <iostream>
#include <queue>
#include <string>

using namespace std;

int board[102][102];
bool visited[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int m;
int k;

int main(void) {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x;
        int y;

        cin >> x >> y;

        board[x - 1][y - 1] = 1;
    }

    fill(&visited[0][0], &visited[n - 1][m], false);

    int sumOfArea = 0;
    int maxOfSize = 0;

    queue<pair<int, int>> queue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || visited[i][j]) {
                continue;
            }

            visited[i][j] = true;

            queue.push({i, j});

            sumOfArea = 0;

            while(!queue.empty()) {
                pair<int, int> currentPos = queue.front();
                queue.pop();
                sumOfArea++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = currentPos.first + dx[dir];
                    int ny = currentPos.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }

                    if (board[nx][ny] == 0 || visited[nx][ny]) {
                        continue;
                    }

                    visited[nx][ny] = true;

                    queue.push({nx, ny});
                }
            }

            maxOfSize = max(maxOfSize, sumOfArea);
        }
    }

    cout << maxOfSize << "\n";
}