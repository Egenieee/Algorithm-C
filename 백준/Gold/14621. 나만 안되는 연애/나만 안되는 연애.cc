#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

#define MALE 1
#define FEMALE 2

int inputN, inputM;
int arr[1001];
int mOrF[1001];

struct Edge {
	int one, two;
	int price;
};

vector<Edge> edges;

bool compare(Edge one, Edge two) {
	return one.price < two.price;
}

void init() {
	for (int i = 0; i < inputN; i++) {
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

	cin >> inputN >> inputM;

	for (int i = 0; i < inputN; i++) {
		string maleOrFemale;

		cin >> maleOrFemale;
		
		if (maleOrFemale == "M") {
			mOrF[i] = MALE;
		}
		else {
			mOrF[i] = FEMALE;
		}
	}

	for (int i = 0; i < inputM; i++) {
		int from, to, price;
		cin >> from >> to >> price;

		edges.push_back({ from - 1, to - 1, price });
	}

	// 비용 기준으로 오름차순 정렬
	sort(edges.begin(), edges.end(), compare);

	int result = 0;
	int targetCnt = inputN - 1;
	int selectedCnt = 0;

	init();

	for (const Edge &edge : edges) {
		int one = edge.one;
		int two = edge.two;
		int curSex = mOrF[one];
		int nextSex = mOrF[two];
		int price = edge.price;

		if (curSex == nextSex) continue;

		if (find(one) == find(two)) continue;

		result += price;
		selectedCnt++;

		setUnion(one, two);

		if (selectedCnt == targetCnt) break;
	}

	if (selectedCnt != targetCnt) {
		cout << "-1";
		return 0;
	}

	cout << result;

	return 0;
}