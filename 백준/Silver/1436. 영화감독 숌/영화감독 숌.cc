#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int movieName = 666;
	int cnt = 1;

	int temp = 0;

	while (cnt != n) {
		movieName++;
		temp = movieName;

		// 영화제목에 6이 3개 이상 들어가는지 확인
		while (temp != 0) {
			// 뒤에서부터 세자리가 666이면 영화 개수 + 1
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			else temp /= 10;  // 일의 자리수 삭제
		}
	}
	cout << movieName;
}