#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputT;
int maxSum;
int board[11][11];
int taken[11];
vector<int> values;

void dfs(int curLevel, int curSum, int prevPlayer) {
    if (curLevel == 11) {
        maxSum = max(maxSum, curSum);
        return;
    }

    for (int j = 0; j < 11; j++) {
        if (board[prevPlayer][j] == 0) continue;
        if (taken[j]) continue;

        taken[j] = 1;
        dfs(curLevel + 1, curSum + board[prevPlayer][j], prevPlayer + 1);
        taken[j] = 0;
    }
}

int main() {
    cin >> inputT;
    
    for (int testCase = 1; testCase <= inputT; testCase++) {
        maxSum = 0;

        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> board[i][j];
            }
            taken[i] = 0;
        }

        dfs(0, 0, 0);

        cout << maxSum << "\n";
        for (int num : values) {
            cout << num << " ";
        }
    }

    return 0;
}