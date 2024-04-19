#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<int> st;

	int target[100001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> target[i];
	}

	vector<char> ans;

	int idx = 0;
	int num = 1;
	while (1) {
		if (!st.empty() && st.top() > target[idx]) {
			cout << "NO";
			return 0;
		}

		if (!st.empty() && st.top() == target[idx]) {
			st.pop();
			ans.push_back('-');
			idx++;
			if (idx == n) break;
		}

		else {
			st.push(num);
			ans.push_back('+');
			num++;
		}

	}

	for (auto iter : ans) {
		cout << iter << "\n";
	}
}