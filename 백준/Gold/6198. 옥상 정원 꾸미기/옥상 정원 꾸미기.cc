#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int inputN;

int main() {
    cin >> inputN;

    stack<int> myStack;

    int number;
    long long cnt = 0;
    cin >> number;

    myStack.push(number);

    for (int i = 0; i < inputN - 1; i++) {
        int floors;
        cin >> floors;

        // 스택에 넣기 전에 자기보다 큰게 나올때까지 pop
        while (!myStack.empty() && myStack.top() <= floors) {
            myStack.pop();
        }

        cnt += myStack.size();
        myStack.push(floors);
    }

    cout << cnt;

    return 0;
}