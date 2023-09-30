#include <iostream>
#include <string>

using namespace std;

int isPalindromeWithLeftStart(string str) {
    int pointerOne = 0;
    int pointerTwo = str.size() - 1;

    int count = 0;

    while(pointerOne < pointerTwo) {
        if (str[pointerOne] != str[pointerTwo]) {
            // 왼쪽 포인터부터 옮기고 확인
            if (str[pointerOne + 1] == str[pointerTwo]) {
                pointerOne++;
            } else if (str[pointerOne] == str[pointerTwo - 1]) {
                pointerTwo--;
            } else { // 어떻게 옮겨도 값이 같지 않다면?
                return 2;
            }

            // 알파벳 하나 뺏다는 의미로 count하나 증가시킴
            count++;
        }

        pointerOne++;
        pointerTwo--;

        if (count > 1) return 2;
    }

    if (count == 1) return 1;

    return 0;
}

int isPalindromeWithRightStart(string str) {
    int pointerOne = 0;
    int pointerTwo = str.size() - 1;

    int count = 0;

    while(pointerOne < pointerTwo) {
        if (str[pointerOne] != str[pointerTwo]) {
            // 오른쪽 포인터부터 옮기고 확인
            if (str[pointerOne] == str[pointerTwo - 1]) {
                pointerTwo--;
            } else if (str[pointerOne + 1] == str[pointerTwo]) {
                pointerOne++;
            } else { // 어떻게 옮겨도 값이 같지 않다면?
                return 2;
            }

            // 알파벳 하나 뺏다는 의미로 count하나 증가시킴
            count++;
        }

        pointerOne++;
        pointerTwo--;

        if (count > 1) return 2;
    }

    if (count == 1) return 1;

    return 0;
}

int main(void) {
    int T;
    string str;

    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        cin >> str;

        cout << min(isPalindromeWithLeftStart(str), isPalindromeWithRightStart(str)) << "\n";
    }

    return 0;
}