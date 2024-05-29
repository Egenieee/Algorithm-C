#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int inputN, inputM;

struct Path {
	int from;
	int to;
	double dist;
};

bool compare(Path one, Path two) {
	return one.dist < two.dist;
}

vector<pair<int, int>> gods; // 우주신 좌표 저장
vector<Path> paths; // 후보 통로
int parents[1001];

void init() {
	for (int i = 1; i <= inputN; i++) {
		parents[i] = i;
	}
}

int find(int target) {
	if (parents[target] == target) return target;

	int ret = find(parents[target]);
	parents[target] = ret;

	return ret;
}

void setUnion(int one, int two) {
	int bossOne = find(one);
	int bossTwo = find(two);

	if (bossOne == bossTwo) return;

	parents[bossTwo] = bossOne;
}

double getDist(int one, int two) {
	pair<int, int> onePos = gods[one];
	pair<int, int> twoPos = gods[two];

	double dx = pow(onePos.first - twoPos.first, 2);
	double dy = pow(onePos.second - twoPos.second, 2);

	return sqrt(dx + dy);
}

int main() {
	cin >> inputN >> inputM;

	gods.push_back({ 0, 0 });

	for (int i = 0; i < inputN; i++) {
		int x, y;
		cin >> x >> y;

		gods.push_back({ x, y });
	}

	for (int i = 1; i <= inputN; i++) {
		int from = i;
		for (int j = i + 1; j <= inputN; j++) {
			int to = j;
			double dist = getDist(from, to);

			paths.push_back({ from, to, dist });
		}
	}

	init();

	double price = 0.0;
	int targetCnt = inputN - 1;
	int curCnt = 0;

    sort(paths.begin(), paths.end(), compare);
	
	// 이미 연결된 번호 입력 받아서 바로 setUnion하기
	for (int i = 0; i < inputM; i++) {
		int one, two;
        int a, b;

		cin >> a >> b;

        one = a;
        two = b;

		if (find(one) == find(two)) continue;

		setUnion(one, two);
		curCnt++;

		if (curCnt == targetCnt) break;
	}

	// 연결 안된 애들 최소 비용으로 연결하기
	for (int i = 0; i < paths.size(); i++) {
		if (curCnt == targetCnt) break;

		int one = paths[i].from;
		int two = paths[i].to;
		double dist = paths[i].dist;

		if (find(one) == find(two)) continue;

		setUnion(one, two);
		price += dist;
		curCnt++;
	}

	double answer = (double) round(100 * price) / 100.0;

	cout << fixed;
	cout.precision(2);
	cout << answer;

	return 0;
}