#include <iostream>
#include <queue>
using namespace std;

struct Fish {
	int y, x, dist;
};

int n;
int map[21][21];
bool visited[21][21];

int sharkY, sharkX;
int sharkSize = 2;
int ate;
int nowTime;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

bool bfs(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }

    int fishY = n;
    int fishX = n;
    int fishDist = 1e9;

    queue<Fish> q;
    q.push({sharkY, sharkX, 0 });
    visited[sharkY][sharkX] = true;
    while (!q.empty()){
        Fish now = q.front();

        if (now.dist >= fishDist){
            sharkY = fishY;
            sharkX = fishX;
            nowTime += fishDist;
            ate++;
            if (ate == sharkSize){
                ate = 0;
                sharkSize++;
            }
            map[fishY][fishX] = 0;
            return true;
        }

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = now.y + dir[i][0];
            int nx = now.x + dir[i][1];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (visited[ny][nx] || map[ny][nx] > sharkSize) continue;

            visited[ny][nx] = true;
            if (map[ny][nx] > 0 && map[ny][nx] < sharkSize) {
                if (fishDist >= now.dist + 1)
                {
                    fishDist = now.dist + 1;
                    if (fishY >= ny)
                    {
                        if (fishY == ny)
                        {
                            if (fishX >= nx)
                                fishX = nx;
                        }
                        else
                        {
                            fishY = ny;
                            fishX = nx;
                        }
                    }
                }
            }
            q.push({ny, nx, now.dist + 1 });
        }
    }
    return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			// 아기 상어 위치
			if (map[i][j] == 9) {
				sharkY = i;
				sharkX = j;
				map[i][j] = 0;
			}
		}
	}

	while (1) {
		if (!bfs()) break;
	}

	cout << nowTime << "\n";
}