#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputT;
int inputN;

int memo[11];

int main() {
    cin >> inputT;

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for (int i = 4; i < 11; i++) {
        memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }

    for (int t = 0; t < inputT; t++) {
        cin >> inputN;

        cout << memo[inputN] << "\n";
    }

    return 0;
}