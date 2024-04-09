#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int inputN;

int main() {
    cin >> inputN;
    
    stack<int> myStack;
    vector<int> tops;
    vector<int> answer;

    for (int i = 0; i < inputN; i++) {
        int num;
        cin >> num;

        tops.push_back(num);
    }


    for (int i = 0; i < inputN; i++) {
        int curNum = tops[i];

        if (myStack.empty()) {
            myStack.push(i + 1);
            answer.push_back(0);
            continue;
        }

        // 현재 수가 스택의 top보다 클때까지 pop하기
        while (!myStack.empty() && tops[myStack.top() - 1] <= curNum) {
            myStack.pop();
        }

        if (myStack.empty()) {
            answer.push_back(0);
        }
        else {
            answer.push_back(myStack.top());
        }
        
        myStack.push(i + 1);
    }

    for (int idx : answer) {
        cout << idx << " ";
    }

    return 0;
}