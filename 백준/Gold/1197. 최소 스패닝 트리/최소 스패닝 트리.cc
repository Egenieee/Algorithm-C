#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int inputV, inputE;
int arr[10001];

struct Node {
	int a, b;
	int price;
};

vector<Node> lines;

bool compare(Node one, Node two) {
	return one.price < two.price;
}

void init() {
	for (int i = 0; i < 10001; i++) {
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

int main() {

	cin >> inputV >> inputE;

	for (int i = 0; i < inputE; i++) {
		int a, b, price;
		cin >> a >> b >> price;

		lines.push_back({ a, b, price });
	}

	// 비용 기준으로 오름차순 정렬
	sort(lines.begin(), lines.end(), compare);

	int result = 0;
	int targetCnt = inputV - 1;
	int selectedCnt = 0;

	init();

	for (Node line : lines) {
		int a = line.a;
		int b = line.b;
		int price = line.price;

		if (find(a) == find(b)) continue;

		result += price;
		selectedCnt++;

		setUnion(a, b);

		if (selectedCnt == targetCnt) break;
	}

	cout << result;

	return 0;
}