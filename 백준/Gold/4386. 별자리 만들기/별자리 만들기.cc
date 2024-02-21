#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

struct Edge {
	int one;
	int two;
	double price;
};

int inputN;
int inputM;
int parents[100001];

pair<int, int> stars[101];

vector<Edge> edges;

bool compare(Edge one, Edge two) {
	return one.price < two.price;
}

void init() {
	for (int i = 0; i <= 100000; i++) {
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
	int oneBoss = find(one);
	int twoBoss = find(two);

	if (oneBoss == twoBoss) return;

	parents[twoBoss] = oneBoss;
}

int main() {
	cin >> inputN;

	for (int i = 0; i < inputN; i++) {
		double y, x;
		cin >> y >> x;

		stars[i].first = y;
		stars[i].second = x;
	}

	for (int i = 0; i < inputN; i++) {
		for (int j = i + 1; j < inputN; j++) {
			double dist = sqrt(pow(stars[i].first - stars[j].first, 2) + pow(stars[i].second - stars[j].second, 2));

			edges.push_back({ i, j, dist });
		}
	}

	sort(edges.begin(), edges.end(), compare);

	double result = 0;
	int targetCnt = inputN - 1;
	int selectedCnt = 0;

	init();

	for (const Edge& edge : edges) {
		int one = edge.one;
		int two = edge.two;
		double price = edge.price;

		if (selectedCnt == targetCnt) break;

		if (find(one) == find(two)) continue;

		result += price;
		selectedCnt++;

		setUnion(one, two);
	}

	cout << fixed;
	cout.precision(2);

	cout << result;

	return 0;
}