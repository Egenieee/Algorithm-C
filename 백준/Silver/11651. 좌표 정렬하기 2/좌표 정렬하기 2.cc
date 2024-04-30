#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;


	int idx = 0;
	while (idx != n) {
		int x, y;
		cin >> x >> y;
		arr[idx] = { y, x };
		idx++;
	}

	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		cout << arr[i].second << " " << arr[i].first << "\n";
	}
}