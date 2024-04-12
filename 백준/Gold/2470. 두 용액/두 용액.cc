#include <iostream>
#include <algorithm>
using namespace std;

int a, b;
int arr[100001];
int minAns = 21e8;

void twoPointer(int start, int end) {
	while (start < end) {
		int now = arr[start] + arr[end];

		if (now == 0) {
			a = arr[start];
			b = arr[end];
			return;
		}

		if (abs(0 - minAns) > abs(0 - now)) {
			minAns = now;
			a = arr[start];
			b = arr[end];
		}

		if (now < 0) {
			start++;
		}

		else {
			end--;
		}

	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	// 정렬
	sort(arr, arr + n);

	twoPointer(0, n - 1);

	cout << a << " " << b << "\n";
}