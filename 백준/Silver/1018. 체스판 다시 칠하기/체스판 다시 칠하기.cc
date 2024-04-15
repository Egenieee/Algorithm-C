#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN;
int inputM;

char board[51][51];
int minCnt;

void cut(int startY, int startX) {

    int blackCnt = 0;
    for (int i = startY; i < startY + 8; i++) {
        for (int j = startX; j < startX + 8; j++) {
            int row = i - startY;
            int col = j - startX;

            if (row % 2 == 0 && col % 2 == 0 && board[i][j] == 'B') {
                blackCnt++;
            }
            else if (row % 2 == 0 && col % 2 == 1 && board[i][j] == 'W') {
                blackCnt++;
            }
            else if (row % 2 == 1 && col % 2 == 0 && board[i][j] == 'W') {
                blackCnt++;
            }
            else if (row % 2 == 1 && col % 2 == 1 && board[i][j] == 'B') {
                blackCnt++;
            }
        }
    }

    int whiteCnt = 0;
    for (int i = startY; i < startY + 8; i++) {
        for (int j = startX; j < startX + 8; j++) {
            int row = i - startY;
            int col = j - startX;

            if (row % 2 == 0 && col % 2 == 0 && board[i][j] == 'W') {
                whiteCnt++;
            }
            else if (row % 2 == 0 && col % 2 == 1 && board[i][j] == 'B') {
                whiteCnt++;
            }
            else if (row % 2 == 1 && col % 2 == 0 && board[i][j] == 'B') {
                whiteCnt++;
            }
            else if (row % 2 == 1 && col % 2 == 1 && board[i][j] == 'W') {
                whiteCnt++;
            }
        }
    }

    minCnt = min(minCnt, 64 - blackCnt);
    minCnt = min(minCnt, 64 - whiteCnt);
}

int main() {
    cin >> inputN >> inputM;
    minCnt = 999999999;

    for (int i = 0; i < inputN; i++) {
        string oneLine;
        cin >> oneLine;
        for (int j = 0; j < inputM; j++) {
            board[i][j] = oneLine[j];
        }
    }

    for (int i = 0; i <= inputN - 8; i++) {
        for (int j = 0; j <= inputM - 8; j++) {
            cut(i, j);
        }
    }

    cout << minCnt;

    return 0;
}