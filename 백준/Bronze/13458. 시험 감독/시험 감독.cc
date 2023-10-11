#include <iostream>
#include <cmath>

using namespace std;

int inputN;
int inputB;
int inputC;

long long totalCount;

int main(void) {
    cin >> inputN;

    int examRooms[inputN];
    totalCount = 0;

    for (int i = 0; i < inputN; i++) {
        cin >> examRooms[i];
    }

    cin >> inputB >> inputC;

    // 1. 전체 방 인원에서 총감독관이 감시할 수 있는 인원 빼기
    totalCount += inputN;
    for (int i = 0; i < inputN; i++) {
        examRooms[i] -= inputB;

        if (examRooms[i] < 0) {
            examRooms[i] = 0;
        }
    }

    // 2. 시험장마다 전체 방 인원 / 부감독관 감시 인원으로 나눈 몫 (올림) 더하기
    for (int i = 0; i < inputN; i++) {
        int sub = ceil((double)examRooms[i] / inputC);

        totalCount += sub;
    }

    cout << totalCount << "\n";

    return 0;
}