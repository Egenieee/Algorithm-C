#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int inputN, inputM;
int landNum;
int board[11][11];
int visited[11][11];

int arr[10];

vector<pair<int, int>> nodePos[11];

struct Edge {
	int one, two;
	int price;
};

vector<Edge> edges;

bool compare(Edge one, Edge two) {
	return one.price < two.price;
}

void init() {
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}
}

int find(int target) {
	if (arr[target] == target) return target;

	int ret = find(arr[target]);
	arr[target] = ret;
	return ret;
}

void setUnion(int one, int two) {
	int t1 = find(one);
	int t2 = find(two);

	if (t1 == t2) return;

	arr[t2] = t1;
}

void initVisited() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			visited[i][j] = 0;
		}
	}
}

void getLandNumber() {
	landNum = 1;
	initVisited();
	
	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			if (board[i][j] == 0 || visited[i][j]) continue;
			
			queue<pair<int, int>> myQ;
			visited[i][j] = 1;
			myQ.push({ i, j });
			board[i][j] = landNum;
			
			while (!myQ.empty()) {
				int curY = myQ.front().first;
				int curX = myQ.front().second;
				myQ.pop();

				nodePos[landNum].push_back({ curY, curX });

				for (int dir = 0; dir < 4; dir++) {
					int ny = curY + dy[dir];
					int nx = curX + dx[dir];

					if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;
					if (visited[ny][nx] || board[ny][nx] == 0) continue;

					visited[ny][nx] = 1;
					board[ny][nx] = landNum;
					myQ.push({ ny, nx });
				}
			}
			landNum++;
		}
	}
}

void getBridgesDist() {
	// 각 섬의 좌표마다 다른 섬과 이어지는지 확인하기
	for (int land = 1; land < landNum; land++) {
		for (int pos = 0; pos < nodePos[land].size(); pos++) {
			// 현재 좌표의 동서남북을 확인했을 때 다른 섬이 있다면, 그 거리만큼 edges에 넣기
			int curY = nodePos[land][pos].first;
			int curX = nodePos[land][pos].second;

			for (int dir = 0; dir < 4; dir++) {
				int curDist = 1;

				while(true) {
					int ny = curY + dy[dir] * curDist;
					int nx = curX + dx[dir] * curDist;

					if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) break;
					if (board[ny][nx] == land) break;

					if (board[ny][nx] != land && board[ny][nx] != 0) {
						edges.push_back({ land, board[ny][nx], curDist - 1 });
						break;
					}

					curDist++;
				}
			}
		}
	}
}
 
int main() {

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		for (int j = 0; j < inputM; j++) {
			cin >> board[i][j];
		}
	}
	
	// flood fill로 각 섬에 번호 붙이기
	getLandNumber();

	// 각 섬에서 섬으로 놓을 수 있는 다리 거리 구하기
	getBridgesDist();

	// 비용 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end(), compare);

	int result = 0;
	int targetCnt = landNum - 2;
	int selectedCnt = 0;

	init();

	for (const Edge& edge : edges) {
		int one = edge.one;
		int two = edge.two;
		int dist = edge.price;

		if (dist <= 1) continue;
		if (find(one) == find(two)) continue;

		result += dist;
		selectedCnt++;

		setUnion(one, two);

		if (selectedCnt == targetCnt) break;
	}

	if (selectedCnt != targetCnt) {
		cout << "-1";
		return 0;
	}

	cout << result << "\n";

	return 0;
}