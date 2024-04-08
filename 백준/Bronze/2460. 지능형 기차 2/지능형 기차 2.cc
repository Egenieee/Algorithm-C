#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int curCnt;
int maxCnt;

int main() {
    int in, out;

    for (int i = 0; i < 10; i++) {
        cin >> out >> in;

        if (i == 0) {
            curCnt += in;
        }
        else if (i == 9) {
            curCnt -= out;
        }
        else {
            curCnt -= out;
            curCnt += in;
        }

        maxCnt = max(maxCnt, curCnt);
    }

    cout << maxCnt;

    return 0;
}