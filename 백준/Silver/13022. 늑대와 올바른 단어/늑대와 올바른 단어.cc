#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inputStr;

int getN() {
    int nCount = 0;

    for (int i = 0; i < inputStr.size(); i++) {
        if (inputStr[i] == 'w') {
            nCount++;
        } else {
            break;
        }
    }

    if (nCount == 0) return -1;

    return nCount;
}

int isValidWord() {
    int n = getN();

    // n이 -1이면 순서가 처음부터 잘못되었다는 뜻이므로 0 리턴
    if (n == -1) return 0;

    // o, l, f가 각각 n번 나오는 지 확인
    int index = n;
    for (int i = index; i < index + n; i++) {
        if (inputStr[i] != 'o' || inputStr[i] != 'o') return 0;
    }
    
    index += n;

    for (int i = index; i < index + n; i++) {
        if (inputStr[i] != 'l' || inputStr[i] != 'l') return 0;
    }

    index += n;

    for (int i = index; i < index + n; i++) {
        if (inputStr[i] != 'f' || inputStr[i] != 'f') return 0;
    }

    index += n;

    string pattern = inputStr.substr(0, index);

    // 위에서 구한 패턴과 원래 문자열 길이가 같다면 올바른 문자
    if (pattern.size() == inputStr.size()) return 1;

    // input string에 위에서 구한 패턴이 모두 들어가 있으면 올바른 문자
    int pos = 0;

    while ((pos = inputStr.find(pattern)) != string::npos){
        inputStr.replace(pos, pattern.size(), "");
    }

    if (inputStr == "") return 1;

    return isValidWord();
}

int main(void) {
    cin >> inputStr;

    cout << isValidWord() << "\n";

    return 0;
}