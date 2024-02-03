#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN, inputK, inputA, inputB;
int arr[101];

int main() {

    cin >> inputN >> inputK >> inputA >> inputB;

    for (int i = 0; i < inputN; i++) {
        arr[i] = inputK;
    }

    int time = 0;
    int waterCnt = inputN / inputA;

    while(true) {
        int startIdx = time % waterCnt;
        startIdx = (startIdx * inputA);

        // 돌아가면서 A개씩 물주기 
        for (int i = 0; i < inputA; i++) {
            arr[startIdx + i] += inputB;
        }

        // 수분 감소
        for (int i = 0; i < inputN; i++) {
            arr[i]--;
        }

        // 죽은 캣잎이 있는지 확인
        for (int i = 0; i < inputN; i++) {
            if (arr[i] == 0) {
                cout << time + 1;
                return 0;
            }
        }

        time++;
    }

    return 0;
}