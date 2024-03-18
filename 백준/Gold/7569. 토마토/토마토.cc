#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct pos {
	int z;
	int y;
	int x;
};

int inputM, inputN, inputH;
int board[101][101][101];
int visited[101][101][101];
queue<pos> myQ;

int day;
bool isValid;

// 모든 토마토가 익었는지 확인하기
void checkAllTomatos() {
	for (int h = 0; h < inputH; h++) {
		for (int i = 0; i < inputN; i++) {
			for (int j = 0; j < inputM; j++) {
				if (board[h][i][j] == 0) {
					isValid = false;
					return;
				}
			}
		}
	}

	isValid = true;
	return;
}

int main() {

	cin >> inputM >> inputN >> inputH;

	for (int h = 0; h < inputH; h++) {
		for (int i = 0; i < inputN; i++) {
			for (int j = 0; j < inputM; j++) {
				cin >> board[h][i][j];

				if (board[h][i][j] == 1) {
					myQ.push({ h, i, j });
				}
			}
		}
	}
	
	// queue에 넣은 위치부터 퍼뜨리기
	while (!myQ.empty()) {
		int size = myQ.size();
		day++;

		for (int i = 0; i < size; i++) {
			pos curPos = myQ.front();
			myQ.pop();

			visited[curPos.z][curPos.y][curPos.x] = 1;

			for (int dir = 0; dir < 6; dir++) {
				int nz = curPos.z + dz[dir];
				int ny = curPos.y + dy[dir];
				int nx = curPos.x + dx[dir];

				if (nz < 0 || nz >= inputH || ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;
				if (board[nz][ny][nx] != 0 || visited[nz][ny][nx]) continue;

				visited[nz][ny][nx] = 1;
				board[nz][ny][nx] = 1;
				myQ.push({ nz, ny, nx });
			}
		}
	}

	checkAllTomatos();

	if (isValid) {
		cout << day - 1;
	}
	else {
		cout << -1;
	}

	return 0;
}