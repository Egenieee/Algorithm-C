#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> words;
string alpha[5] = {"A", "E", "I", "O", "U"};

void addWord(int maxLen, string str) {
    if (maxLen == str.length()) {
        words.push_back(str);
        return;
    }

    for (int i = 0; i < 5; i++) {
        addWord(maxLen, str + alpha[i]);
    }
}

int solution(string word) {
    // A, E, I, O, U로 만들 수 있는 5자 이하의 단어
    for (int i = 0; i <=  5; i++) {
        addWord(i, "");
    }

    sort(words.begin(), words.end());

    return find(words.begin(), words.end(), word) - words.begin();
}