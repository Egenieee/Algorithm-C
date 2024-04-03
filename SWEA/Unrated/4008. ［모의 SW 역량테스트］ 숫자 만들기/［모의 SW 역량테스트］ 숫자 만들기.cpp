#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int opers[4];
int nums[13];

int minValue = 1e9;
int maxValue = -1e9;

void input() {
	cin >> n;

	for (int i = 0; i < 4; i++) {
		cin >> opers[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
}

void dfs(int pick, int value) {
	if (pick == n - 1) {

		minValue = min(value, minValue);
		maxValue = max(value, maxValue);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opers[i] == 0) continue;

		opers[i]--;
		if (i == 0) {
			dfs(pick + 1, value + nums[pick + 1]);
		}
		else if (i == 1) {
			dfs(pick + 1, value - nums[pick + 1]);
		}
		else if (i == 2) {
			dfs(pick + 1, value * nums[pick + 1]);
		}
		else if (i == 3) {
			dfs(pick + 1, value / nums[pick + 1]);
		}

		opers[i]++;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		minValue = 1e9;
		maxValue = -1e9;

		input();

		dfs(0, nums[0]);

		cout << "#" << tc << " " << maxValue - minValue << "\n";
	}

}