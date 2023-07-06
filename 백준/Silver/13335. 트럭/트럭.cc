#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int w;
    int l;
    int time = 0;
    
    cin >> n >> w >> l;

    int trucks[n];

    for (int i = 0; i < n; i++) {
        cin >> trucks[i];
    }

    queue<int> bridge;

    int orderOfTruck = 0;
    int sumOfTruckWeight = 0;

    for (int i = 0; i < n; i++) {
        // 하나의 트럭이 다리 지나는 반복문
        while(true) {
            // 다리 위에 있는 트럭의 개수가 다리의 개수와 같다면, 트럭 하나 제거
            if (bridge.size() == w) {
                sumOfTruckWeight -= bridge.front();
                bridge.pop();
            }

            // 현재 다리 위에 있는 트럭의 무게 총합에 다음 트럭을 더했을 때, 제한 무게 충족된다면, 새로운 트럭 추가 
            // 그렇지 않다면, 무게가 0인 가짜 트럭 추가해서 다른 트럭이 다리를 건너지 못하게 한다.
            if (sumOfTruckWeight + trucks[i] <= l) break;

            bridge.push(0);
            time++;
        }

        // 새로운 트럭 추가
        bridge.push(trucks[i]);
        sumOfTruckWeight += trucks[i];
        time++;
    }
    
    // 마지막 트럭이 건너는 시간(다리 길이) 더한 후 리턴
    cout << time + w << "\n";

    return 0;
}