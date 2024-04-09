#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN;

int main() {
    cin >> inputN;
    vector<int> numbers;
    vector<int> answer(inputN);
    stack<int> myStack;

    for (int i = 0; i < inputN; i++) {
        int num;
        cin >> num;

        numbers.push_back(num);
    }

    for (int i = 0; i < inputN; i++) {
        int curNum = numbers[i];

        while (!myStack.empty() && numbers[myStack.top()] < curNum) {
            answer[myStack.top()] = curNum;
            myStack.pop();
        }

        myStack.push(i);
    }

    while (!myStack.empty()) {
        answer[myStack.top()] = -1;
        myStack.pop();
    }

    for (int num : answer) {
        cout << num << " ";
    }

    return 0;
}