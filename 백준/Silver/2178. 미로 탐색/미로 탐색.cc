#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int board[102][102];
int dist[102][102];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    fill(&dist[0][0], &dist[n - 1][m], -1);

    queue<pair<int, int>> queue;

    dist[0][0] = 1;
    queue.push({0, 0});

    while(!queue.empty()) {
        pair<int, int> currentPos = queue.front();
        queue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = currentPos.first + dx[dir];
            int ny = currentPos.second + dy[dir];

            // 범위를 벗어났다면 패스
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 이미 방문한 칸이라 거리가 존재하거나 막힌 칸이면 패스
            if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;

            // 거리 표시
            dist[nx][ny] = dist[currentPos.first][currentPos.second] + 1;
            queue.push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1] << "\n";

    return 0;
}