#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN, inputK;
string input;

int main() {
    cin >> inputN >> inputK;
    cin >> input;

    int maxIdx = -1;
    string answer = "";

    for (int i = 0; i < inputN - inputK; i++) {
        int maxValue = 0;

        for (int j = maxIdx + 1; j <= i + inputK; j++) {
            int curNum = input[j] - '0';

            if (curNum > maxValue) {
                maxValue = curNum;
                maxIdx = j;
            }

            if (maxValue == 9) break;
        }

        answer += maxValue + '0';
    }

    cout << answer;

    return 0;
}