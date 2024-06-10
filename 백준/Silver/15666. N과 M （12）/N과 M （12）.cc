#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int inputN, inputM;

vector<int> numbers;
vector<int> selected;

unordered_map<string, int> myMap;

int taken[10];

bool isAvaliable() {
    string number = "";

    for (int i = 0; i < inputM; i++) {
        number += to_string(selected[i]);
        number += ' ';
    }

    if (myMap[number] > 0) return false;

    myMap[number] = 1;

    return true;
}

void print() {
    for (int num : selected) {
        cout << num << " ";
    }
    cout << "\n";
}

void dfs(int curLevel, int prev) {
    if (curLevel == inputM) {
        if (isAvaliable()) {
            print();
        }
        return;
    }

    for (int i = prev; i < inputN; i++) {
        selected.push_back(numbers[i]);
        dfs(curLevel + 1, i);
        selected.pop_back();
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

    dfs(0, 0);

    return 0;
}