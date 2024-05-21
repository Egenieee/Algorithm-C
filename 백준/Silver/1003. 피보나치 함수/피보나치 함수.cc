#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int fiboWithZero[41];
int fiboWithOne[41];

void fiboZero(int num) {
	if (num == 0) {
		fiboWithZero[0] = 1;
	}
	else if (num == 1) {
		fiboWithZero[1] = 0;
	}
	else {
		fiboWithZero[num] = fiboWithZero[num - 1] + fiboWithZero[num - 2];
	}
}

void fiboOne(int num) {
	if (num == 0) {
		fiboWithOne[0] = 0;
	}
	else if (num == 1) {
		fiboWithOne[1] = 1;
	}
	else {
		fiboWithOne[num] = fiboWithOne[num - 1] + fiboWithOne[num - 2];
	}
}

void getFiboZero() {
	for (int i = 0; i <= 41; i++) {
		fiboZero(i);
	}
}

void getFiboOne() {
	for (int i = 0; i <= 41; i++) {
		fiboOne(i);
	}
}

int main() {
	int T;

	cin >> T;

	getFiboZero();
	getFiboOne();

	// 각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력
	for (int testCase = 1; testCase <= T; testCase++) {
		int input;
		cin >> input;
		cout << fiboWithZero[input] << " " << fiboWithOne[input] << "\n";
	}
	
	return 0;
 }

// 0 -> 0은 1번 1은 0번
// 1 -> 0은 0번 1은 1번
// 2 -> 0은 1번 1은 1번 
// 3 -> 0은 1번 1은 2번 
// 4 -> 0은 2번 1은 3번
// 5 -> 0은 3번 1은 5번
// 6 -> 0은 5번 1은 8번