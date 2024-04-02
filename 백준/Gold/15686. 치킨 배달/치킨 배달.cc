#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node { int y, x; };

int n, m;
int map[51][51];
bool selected[13];
vector<Node> stores;
vector<Node> homes;
vector<Node> picked;

int minCityDist = 1e9;

void input() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) homes.push_back({ i, j });
			else if (map[i][j] == 2) stores.push_back({ i, j });
		}
	}
}

void findMinDist() {
	int nowMinDist = 0;

	for (int i = 0; i < homes.size(); i++) {
		int nowChickDist = 1e9;
		for (int j = 0; j < m; j++) {
			nowChickDist = min(nowChickDist, abs(homes[i].y - picked[j].y) + abs(homes[i].x - picked[j].x));
		}
		nowMinDist += nowChickDist;
	}
	minCityDist = min(minCityDist, nowMinDist);
}

void dfs(int pick, int now) {

	if (pick == m) {
		findMinDist();
		return;
	}

	for (int i = now; i < stores.size(); i++) {
		if (selected[i]) continue;

		selected[i] = true;
		picked.push_back(stores[i]);
		dfs(pick + 1, i);
		selected[i] = false;
		picked.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();

	// 치킨집 중 m개 고르기 (조합)
	dfs(0, 0);

	cout << minCityDist;
}