#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int inputN, inputM;

vector<int> numbers;
vector<int> selected;

int taken[10001];

void print() {
    for (int num : selected) {
        cout << num << " ";
    }
    cout << "\n";
}

void dfs(int curLevel) {
    if (curLevel == inputM) {
        print();
        return;
    }

    for (int i = 0; i < inputN; i++) {
        if (taken[numbers[i]]) continue;

        taken[numbers[i]] = 1;
        selected.push_back(numbers[i]);
        dfs(curLevel + 1);
        selected.pop_back();
        taken[numbers[i]] = 0;
    }
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    dfs(0);
}