#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int cnt = 0;

	// 0의 개수는 10이 곱해진 횟수
	// 10 = 2 * 5이고, 보통 2의 개수보다 5의 개수가 더 적기 때문에
	// 5의 개수를 구하면 0의 개수를 구할 수 있다.
	// 주의! 25는 5가 2번 곱해진 것, 0이 2개
	//		125는 5가 3번 곱해진 것, 0이 3개
	// 5의 제곱수일 때는 0이 1개 더 많기 때문에 거듭제곱수로 cnt
	for (int i = 5; i <= n; i *= 5) {
		cnt += (n / i);
	}

	cout << cnt;
}