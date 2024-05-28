#include <iostream>
#include <vector>

using namespace std;

// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
// 고른 수열은 비내림차순이어야 한다.
// 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

int inputN, inputM;
vector<int> numbers;

void dfs(int curLevel, int prev) {
    if (curLevel == inputM) {
        for (int number : numbers) {
            cout << number << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = prev; i <= inputN; i++) {
        numbers.push_back(i);
        dfs(curLevel + 1, i);
        numbers.pop_back();
    }
}

int main() {
    cin >> inputN >> inputM;

    dfs(0, 1);

    return 0;
}