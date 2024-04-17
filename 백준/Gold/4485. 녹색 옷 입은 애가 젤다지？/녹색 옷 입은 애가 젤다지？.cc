#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x, thief;
	
	bool operator<(Node right) const {
		return thief > right.thief;
	}
};

int n;
int map[126][126];
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int dijkstra(int n) {
	priority_queue<Node> pq;

	int dist[126][126] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 1e9;
		}
	}

	dist[0][0] = map[0][0];
	pq.push({ 0, 0, map[0][0] });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dir[i][0];
			int nx = now.x + dir[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			int nextThief = now.thief + map[ny][nx];
			if (nextThief >= dist[ny][nx]) continue;

			dist[ny][nx] = nextThief;
			pq.push({ ny, nx, nextThief });
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int turn = 0;
	while (1) {
		++turn;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		cout << "Problem " << turn << ": " << dijkstra(n) << "\n";
	}

}