#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[501][501];
int maxValue[501][501];
int inputN;

int main() {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < i + 1; j++) {
            int num;
            cin >> num;

            board[i][j] = num;
        }
    }

    maxValue[0][0] = board[0][0];

    for (int i = 0; i < inputN - 1; i++) {
        int curRow = i;
        int nextRow = i + 1;

        for (int j = 0; j < i + 1; j++) {
            int leftCol = j;
            int rightCol = j + 1;

            // 아래 행 왼쪽 오른쪽에 각각 값 채울거임
            // 원래 값과 새롭게 더해줄 값 중 더 큰 값으로 갱신하기
            maxValue[nextRow][leftCol] = max(maxValue[nextRow][leftCol], maxValue[curRow][j] + board[nextRow][leftCol]);
            maxValue[nextRow][rightCol] = max(maxValue[nextRow][rightCol], maxValue[curRow][j] + board[nextRow][rightCol]);
        }

    }

    int maxSum = 0;

    for (int i = 0; i < inputN; i++) {
        maxSum = max(maxSum, maxValue[inputN - 1][i]);
    }

    cout << maxSum;

    return 0;
}