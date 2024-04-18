#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string ps;
	while (n--) {
		int now = 0;
		cin >> ps;

		for (int i = 0; i < ps.length(); i++) {
			if (ps[i] == '(') {
				now++;
			}
			else {
				if (now > 0)
					now--;
				else {
					now = 1;
					break;
				}
			}
		}

		if (now == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}