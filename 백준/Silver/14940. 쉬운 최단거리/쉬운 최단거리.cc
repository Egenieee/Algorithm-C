#include <iostream>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[1002][1002];
int dist[1002][1002];

int n;
int m;

int main(void) {
    cin >> n >> m;

    int destX;
    int destY;

    fill(&dist[0][0], &dist[n - 1][m], -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                destX = i;
                destY = j;
            } else if (board[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    queue<pair<int, int>> queue;

    queue.push({destX, destY});
    dist[destX][destY] = 0;

    while(!queue.empty()) {
        pair<int, int> currentPos = queue.front();
        queue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = currentPos.first + dx[dir];
            int ny = currentPos.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (dist[nx][ny] >= 0) continue;

            queue.push({nx, ny});

            dist[nx][ny] = dist[currentPos.first][currentPos.second] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}