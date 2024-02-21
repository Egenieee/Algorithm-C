#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

struct Edge {
	int one;
	int two;
	int price;
};

int inputN;
int inputM;
int parents[100001];

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
	cin >> inputN >> inputM;

	for (int i = 0; i < inputM; i++) {
		int one, two, price;
		cin >> one >> two >> price;

		edges.push_back({ one, two, price });
	}


	sort(edges.begin(), edges.end(), compare);

	int result = 0;
	int targetCnt = inputN - 2;
	int selectedCnt = 0;

	init();

	for (const Edge& edge : edges) {
		int one = edge.one;
		int two = edge.two;
		int price = edge.price;

		if (selectedCnt == targetCnt) break;

		if (find(one) == find(two)) continue;

		result += price;
		selectedCnt++;

		setUnion(one, two);
	}

	cout << result;

	return 0;
}