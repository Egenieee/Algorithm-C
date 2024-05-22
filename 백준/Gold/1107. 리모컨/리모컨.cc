#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int inputN;
int inputM;

int buttons[11];

int main() {
	cin >> inputN >> inputM;

	for (int i = 0; i < inputM; i++) {
		int button;
		cin >> button;
		buttons[button] = 1;
	}
	
	// 100에서부터 +, -로 이동하는 경우가 기본 값
	int minValue = abs(inputN - 100);

	// 숫자패드 누르고 +, -로 이동할 경우
	for (int i = 0; i <= 999999; i++) {
		int flag = 0;
		string strNum = to_string(i);
		int digitCnt = strNum.length();

		for (int j = 0; j < digitCnt; j++) {
			if (buttons[strNum[j] - '0'] == 1) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			minValue = min(minValue, abs(i - inputN) + digitCnt);
		}
	}

	cout << minValue;
 }