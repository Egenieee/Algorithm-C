#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<int> st;
	string cmd;
	int x;

	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			st.push(x);
		}
		else if (cmd == "pop") {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (cmd == "top") {
			if (st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";
		}
		else if (cmd == "size") {
			cout << st.size() << "\n";
		}
		else if (cmd == "empty") {
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}