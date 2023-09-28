#include <vector>
#include <iostream>

using namespace std;

int inputN;
int inputK;

int container[201];
bool hasRobots[201];

bool stop() {
    int count = 0;

    for (int i = 0; i < inputN * 2; i++) {
        if (container[i] == 0) {
            count++;
        }

        if (count >= inputK) {
            return true;
        }
    }

    return false;
}

void moveContainer() {
    // 컨테이너 벨트 한칸 씩 이동
    int size = inputN * 2;
    int lastValue = container[size - 1];

    for (int i = size - 1; i > 0; i--) {
        container[i] = container[i - 1];
    }

    container[0] = lastValue;

    // 컨테이너 벨트 위의 로봇 유무 한칸 씩 이동

    bool lastRobot = hasRobots[size - 1];

    for (int i = size - 1; i > 0; i--) {
        hasRobots[i] = hasRobots[i - 1];
    }

    hasRobots[0] = lastRobot;
}

void moveRobot() {
    int size = inputN * 2;

    for (int i = size - 1; i > 0; i--) {
        // N번째 위치일 경우
        if (i == inputN - 1 && hasRobots[i]) {
            hasRobots[i] = false;
            continue;
        }

        // 나머지 위치일 경우

        // 현재 위치에 로봇이 있고, 이동할 위치에 로봇이 없고 내구도가 1이상인 경우
        if (hasRobots[i] && !hasRobots[i + 1] && container[i + 1] > 0) {
            // 현재 위치에서 로봇 빼기
            hasRobots[i] = false;

            // 다음 위치로 로봇 옮기기
            hasRobots[i + 1] = true;
            container[i + 1]--;

            // 새로 옮긴 위치가 N번째 위치라면 로봇을 내린다
            if (i + 1 == inputN - 1 && hasRobots[i + 1]) {
                hasRobots[i + 1] = false;
            }
        }
    }
}

int main(void) {
    int startIdx = 0;
    int step = 0;

    cin >> inputN >> inputK;

    for (int i = 0; i < inputN * 2; i++) {
        cin >> container[i];
    }

    while(!stop()) {
        // 단계 증가
        step++;

        // 1. 한 칸 이동 -> N 위치에 로봇 있다면 내리기
        moveContainer();

        if (hasRobots[inputN - 1]) {
            hasRobots[inputN - 1] = false;
        }

        // 2. 로봇 옆으로 한 칸 씩 이동
        moveRobot();

        // 3. 0번 인덱스에 로봇 올리기
        if (container[0] > 0 && !hasRobots[0]) {
            container[0]--;
            hasRobots[0] = true;
        }
    }

    cout << step << "\n";

    return 0;
}