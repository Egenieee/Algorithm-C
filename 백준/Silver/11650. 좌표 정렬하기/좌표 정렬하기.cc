#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;

	int n;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	for (auto iter : v) {
		cout << iter.first << " " << iter.second << "\n";
	}
}