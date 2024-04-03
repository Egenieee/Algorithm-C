#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int movieName = 666;
	int cnt = 0;

	int n;
	cin >> n;

	while (1) {
		string strName = to_string(movieName);
		if (strName.find("666") != string::npos) {
			cnt++;
		}

		if (cnt == n) {
			cout << movieName << "\n";
			return 0;
		}

		movieName++;
	}
}