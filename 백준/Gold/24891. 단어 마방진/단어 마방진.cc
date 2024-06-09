#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputL, inputN;

bool taken[21];
bool stop = false;

vector<string> words;
vector<string> answer;

void print() {
    for (int i = 0; i < inputL; i++) {
        cout << answer[i] << "\n";
    }
}

bool isMabangjin() {
    for (int i = 0; i < inputL; i++) {
        for (int j = 0; j < inputL; j++) {
            if (answer[i][j] != answer[j][i]) return false;
        }
    }

    return true;
}

void dfs(int curLevel) {
    if (stop) return;

    if (curLevel == inputL) {
        if (isMabangjin()) {
            print();
            stop = true;
        }
        return;
    }

    for (int i = 0 ; i < inputN; i++) {
        if (taken[i]) continue;

        answer.push_back(words[i]);
        taken[i] = true;
        dfs(curLevel + 1);
        taken[i] = false;
        answer.pop_back();
    }
}

int main() {

    cin >> inputL >> inputN;

    for (int i = 0; i < inputN; i++) {
        string word;
        cin >> word;

        words.push_back(word);
    }

    sort(words.begin(), words.end());

    dfs(0);

    if (!stop) {
        cout << "NONE";
    }

    return 0;
}