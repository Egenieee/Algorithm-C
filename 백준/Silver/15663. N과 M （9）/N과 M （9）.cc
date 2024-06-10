#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int inputN, inputM;

vector<int> numbers;
vector<int> selected;

unordered_map<string, int> myMap;

int taken[10001];

bool isAvaliable() {
    string number = "";

    for (int num : selected) {
        number += to_string(num);
        number += ' ';
    }

    if(myMap[number] > 0) return false;

    myMap[number] = 1;

    return true;
}

void print() {
    for (int i = 0; i < inputM; i++) {
        cout << selected[i] << " ";
    }
    cout << "\n";
}

void dfs(int curLevel) {
    if (curLevel == inputM) {
        if (isAvaliable()) {
            print();
        }
        return;
    }

    for (int i = 0; i < inputN; i++) {
        if (taken[i]) continue;

        taken[i] = 1;
        selected.push_back(numbers[i]);
        dfs(curLevel + 1);
        selected.pop_back();
        taken[i] = 0;
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

    return 0;
}