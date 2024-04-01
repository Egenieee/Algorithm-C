#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x, time;

	bool operator<(Node right) const {
		return time > right.time;
	}
};

int n;
int map[16][16];
int startY, startX, destY, destX;

int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> startY >> startX >> destY >> destX;
}

int dijkstra(int sy, int sx) {
	priority_queue<Node> pq;

	int dist[16][16] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[sy][sx] = 1;
	pq.push({ sy, sx, 1 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (now.y == destY && now.x == destX) return now.time;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1) continue;

			int nc = now.time;

			if (map[ny][nx] == 2) {
				while (nc % 3 != 0) {
					nc++;
				}
			}
			if (dist[ny][nx] <= nc) continue;

			dist[ny][nx] = nc;
			pq.push({ ny, nx, nc + 1});
		}
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {

		input();

		cout << "#" << i << " " << dijkstra(startY, startX) - 1 << "\n";
	}

}