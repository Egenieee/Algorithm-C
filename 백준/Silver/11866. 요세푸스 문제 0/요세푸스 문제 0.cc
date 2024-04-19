#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	
	int ans[1001] = { 0 };

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int idx = 0;
	while (1) {
		if (q.size() == 1) {
			ans[n - 1] = q.front();
			break;
		}
		
		int tmp = 0;
		while (++tmp) {
			if (tmp == k) {
				ans[idx++] = q.front();
				q.pop();
				break;
			}
			q.push(q.front());
			q.pop();
		}
	}

	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n - 1] << ">";
}