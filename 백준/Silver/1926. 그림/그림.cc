#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;

    cin >> n >> m;

    bool visited[n][m];
    int pictures[n][m];

    fill(&visited[0][0], &visited[n-1][m], false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pictures[i][j];
        }
    }

    queue<pair<int, int>> queue;

    int numberOfPictures = 0;
    int sizeOfPicture = 0;
    int biggestPicture = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pictures[i][j] == 0 || visited[i][j]) {
                continue;
            }

            numberOfPictures++; // 그림 개수 추가
            sizeOfPicture = 0; // 그림 크기 초기화

            queue.push({i, j});
            visited[i][j] = true;

            while (!queue.empty()) {
                pair<int, int> currentPos = queue.front();
                queue.pop();
                sizeOfPicture++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = currentPos.first + dx[dir];
                    int ny = currentPos.second + dy[dir];

                    if (nx >= n || nx < 0 || ny >= m || ny < 0) {
                        continue;
                    }

                    if (visited[nx][ny] || pictures[nx][ny] == 0) {
                        continue;
                    }

                    visited[nx][ny] = true;

                    queue.push({nx, ny});
                }
            }

            biggestPicture = max(sizeOfPicture, biggestPicture);
        }
    }

    cout << numberOfPictures << "\n" << biggestPicture;

    return 0;
}