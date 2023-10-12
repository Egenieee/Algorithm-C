#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int board[51][51];
vector<pair<int, int>> housesPos;
vector<pair<int, int>> chickensPos;

vector<int> choiceIdx;

bool isTaken[13];

int inputN;
int inputM;

int minDist;

int getDist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

// 치킨집 중 M개 조합으로 치킨거리 다 구해보고 최소 치킨 거리 리턴
void solution(int count, int prevChicken) {
    if (count == inputM) {
        // 모든 집에서 모든 치킨 집까지 치킨 거리 구하고 가장 가까운 치킨집 찾기
        // 그러고 그 합으로 minDist 갱신하기

        int sumOfDist = 0;

        for (int i = 0; i < housesPos.size(); i++) {
            int eachMinDist = 999999999;

            // 모든 치킨 집으로부터 거리 구해보기
            for (int j = 0; j < choiceIdx.size(); j++) {
                int chickenY = chickensPos[choiceIdx[j]].first;
                int chickenX = chickensPos[choiceIdx[j]].second;
                int houseY = housesPos[i].first;
                int houseX = housesPos[i].second;

                int dist = getDist(chickenY, chickenX, houseY, houseX);
                
                eachMinDist = min(dist, eachMinDist);
            }

            // 가장 가까운 치킨 거리 정하기
            sumOfDist += eachMinDist;
        }

        // cout << "다음과 같이 치킨 집을 뽑았을 때 : ";
        // for (int i = 0; i < choiceIdx.size(); i++) {
        //     cout << choiceIdx[i] << " ";
        // }
        // cout << "\n최소 치킨 거리는 " << sumOfDist << "입니다\n";

        minDist = min(sumOfDist, minDist);

        return;
    }

    // 치킨 집 중 inputM만큼 뽑기
    for (int i = prevChicken; i < chickensPos.size(); i++) {
        if (!isTaken[i]) {
            isTaken[i] = true;
            choiceIdx.push_back(i);
            solution(count + 1, i + 1);
            choiceIdx.pop_back();
            isTaken[i] = false;
        } 
    }
}

int main(void) {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                housesPos.push_back({i, j});
            }

            if (board[i][j] == 2) {
                chickensPos.push_back({i, j});
            }
        }
    }

    minDist = 999999999;

    solution(0, 0);

    cout << minDist << "\n";

    return 0;
}