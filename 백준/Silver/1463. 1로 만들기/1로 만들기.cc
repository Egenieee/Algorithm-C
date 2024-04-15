#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN;

int memo[1000001];

int main() {
    cin >> inputN;

    memo[1] = 0;

    for (int i = 2; i <= inputN; i++) {
        memo[i] = memo[i - 1] + 1;
        if (i % 2 == 0) {
            memo[i] = min(memo[i], memo[i / 2] + 1);
        }

        if (i % 3 == 0) {
            memo[i] = min(memo[i], memo[i / 3] + 1);
        }
    }
    
    cout << memo[inputN];

    return 0;
}