#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int inputN;

pair<int, int> trees[26];

// 루트 -> 왼쪽 -> 오른쪽
void preOrder(int cur) {
    if (cur == -1) return;

    cout << (char) (cur + 'A');
    preOrder(trees[cur].first);
    preOrder(trees[cur].second);
}

// 왼쪽 -> 루트 -> 오른쪽
void inOrder(int cur) {
    if (cur == -1) return;

    inOrder(trees[cur].first);
    cout << (char) (cur + 'A');
    inOrder(trees[cur].second);
}

// 왼쪽 -> 오른쪽 -> 루트
void postOrder(int cur) {
    if (cur == -1) return;

    postOrder(trees[cur].first);
    postOrder(trees[cur].second);
    cout << (char) (cur + 'A');
}

int main() {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        char self, left, right;

        cin >> self >> left >> right; 
        
        if (left != '.') {
            trees[self - 'A'].first = left - 'A';
        } else {
            trees[self - 'A'].first = -1;
        }
        
        if (right != '.') {
            trees[self - 'A'].second = right - 'A';
        } else {
            trees[self - 'A'].second = -1;
        }
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);

    return 0;
}
