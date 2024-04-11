#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

string origin;
string target;

stack<pair<char, int>> myStack;

int main() {
    cin >> origin >> target;

    int idx = 0;

    for (int i = 0; i < origin.size(); i++) {
        char ch = origin[i];

        if (ch == target[idx]) {
            idx++;
        }
        else if (ch != target[idx]) {            
            idx = 0;

            if (ch == target[idx]) {
                idx++;
            }
        }

        myStack.push({ ch, idx });

        if (idx == target.size()) {
            for (int i = 0; i < idx; i++) {
                myStack.pop();
            }
            if (myStack.empty()) {
                idx = 0;
            }
            else {
                idx = myStack.top().second;
            }
        }
    }

    if (myStack.size() == 0) {
            cout << "FRULA";
    }
    else {
        string answer = "";

        while (!myStack.empty()) {
            answer += myStack.top().first;
            myStack.pop();
        }

        reverse(answer.begin(), answer.end());

        cout << answer;
    }

    return 0;
}