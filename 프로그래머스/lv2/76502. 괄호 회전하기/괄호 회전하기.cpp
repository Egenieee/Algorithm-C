#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;


bool isValid(string str, int startIdx, int strSize) {
    stack<char> mStack;
    
    for (int i = startIdx; i < strSize + startIdx; i++) {
        if (mStack.empty()) {
            mStack.push(str[i % strSize]);
        } else {
            if (mStack.top() == '[' && str[i % strSize] == ']') {
                mStack.pop();
            } else if (mStack.top() == '(' && str[i % strSize] == ')') {
                mStack.pop();
            } else if (mStack.top() == '{' && str[i % strSize] == '}'){
                mStack.pop();
            } else {
                mStack.push(str[i % strSize]);
            }
        }
    }
    
    return mStack.size() == 0;
}

int solution(string s) {
    int strSize = s.size();
    int answer = 0;
    
    for (int i = 0; i < strSize; i++) {
        if (isValid(s, i, strSize)) {
            answer++;
        }
    }
    
    return answer;
}