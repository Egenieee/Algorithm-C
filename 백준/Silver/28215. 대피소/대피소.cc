#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN, inputK;
int minDist;
pair<int, int> pos[51];

int main() {
    cin >> inputN >> inputK;
    minDist = 1e9;

    for (int i = 0; i < inputN; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    if (inputK == 1) {
        for (int shelter = 0; shelter < inputN; shelter++) {
            int shelterX = pos[shelter].first;
            int shelterY = pos[shelter].second;
            int maxDist = -1;

            // 모든 집과 대피소 사이 거리 중에 가장 먼 거리 찾기
            for (int home = 0; home < inputN; home++) {
                if (shelter == home) continue;

                int homeX = pos[home].first;
                int homeY = pos[home].second;

                maxDist = max(maxDist, abs(shelterX - homeX) + abs(shelterY - homeY));
            }

            minDist = min(maxDist, minDist);
        }
    }

    else if(inputK == 2) {
        for (int shelterOne = 0; shelterOne < inputN; shelterOne++) {
            for (int shelterTwo = shelterOne; shelterTwo < inputN; shelterTwo++) {
                int shelterOneX = pos[shelterOne].first; 
                int shelterOneY = pos[shelterOne].second;
                int shelterTwoX = pos[shelterTwo].first;
                int shelterTwoY = pos[shelterTwo].second;

                int maxDist = -1;

                for (int home = 0; home < inputN; home++) {
                    if(home == shelterOne || home == shelterTwo) continue;
                    int homeX = pos[home].first;
                    int homeY = pos[home].second;

                    // 두 개의 대피소 중 더 가까운 대피소 거리 구하기
                    int dist = min(abs(homeX - shelterOneX) + abs(homeY - shelterOneY), abs(homeX - shelterTwoX) + abs(homeY - shelterTwoY));
                    maxDist = max(dist, maxDist);
                }

                //cout << shelterOneX << ", " << shelterOneY << " 와 " << shelterTwoX << ", " << shelterTwoY << "일 때, 가장 가까운 대피소 중 가장 멀리 떨어진 값 : " << maxDist << "\n";
                minDist = min(maxDist, minDist);
            }
        }
    }

    else if(inputK == 3) {
        for (int shelterOne = 0; shelterOne < inputN; shelterOne++) {
            for (int shelterTwo = shelterOne; shelterTwo < inputN; shelterTwo++) {
                for (int shelterThree = shelterTwo; shelterThree < inputN; shelterThree++) {
                    int shelterOneX = pos[shelterOne].first; 
                    int shelterOneY = pos[shelterOne].second;
                    int shelterTwoX = pos[shelterTwo].first;
                    int shelterTwoY = pos[shelterTwo].second;
                    int shelterThreeX = pos[shelterThree].first;
                    int shelterThreeY = pos[shelterThree].second;

                    int maxDist = -1;

                    for (int home = 0; home < inputN; home++) {
                        if(home == shelterOne || home == shelterTwo || home == shelterThree) continue;
                        int homeX = pos[home].first;
                        int homeY = pos[home].second;

                        // 세 개의 대피소 중 더 가까운 대피소 거리 구하기
                        int dist = min(abs(homeX - shelterOneX) + abs(homeY - shelterOneY), abs(homeX - shelterTwoX) + abs(homeY - shelterTwoY));
                        dist = min(abs(homeX - shelterThreeX) + abs(homeY - shelterThreeY), dist);
                        maxDist = max(dist, maxDist);
                    }

                    //cout << shelterOneX << ", " << shelterOneY << " 와 " << shelterTwoX << ", " << shelterTwoY << " 와 " << shelterThreeX << ", " << shelterThreeY << "일 때, 가장 가까운 대피소 중 가장 멀리 떨어진 값 : " << maxDist << "\n";
                    minDist = min(maxDist, minDist);
                }
            }
        }
    }

    cout << minDist;

    return 0;
} 