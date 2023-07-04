#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidString(int i, char str);

int getNumberOfTransition(stack<char> stack);

int main(void) {
    string input;
    int order = 1;
    
    while(true) {
        stack<char> stack;
        getline(cin, input);
        
        if (input.find("-") != string::npos) {
            break;
        }
        
        // 안정적인 괄호 삭제
        for (int i = 0; i < input.length(); i++) { 
            if (stack.empty()) {
                stack.push(input[i]);
            } else {
                if (stack.top() == '{' && input[i] == '}') {
                    stack.pop();
                } else {
                    stack.push(input[i]);
                }   
            }
        }

        // stack 돌면서 안정적인 문자열로 변환하기
        // 끝에서부터 순서가 짝수일 경우는 '}' 홀수일 경우는 '{'
        
        cout << order << ". " << getNumberOfTransition(stack) <<"\n";

        order++;
    }

    return 0;
}

int getNumberOfTransition(stack<char> stack) {
    int answer = 0;
    int order = 0;

    while(!stack.empty()) {
        char str = stack.top();
        stack.pop();

        if (!isValidString(order, str)) {
            answer++;
        }

        order++;
    }

    return answer;
}

bool isValidString(int i, char str) {
    if (i % 2 == 0) {
        return str == '}';
    } else {
        return str == '{';
    }
}