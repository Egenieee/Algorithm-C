#include <iostream>
#include <vector>
#include <unordered_map>
//#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> oriBoard(101, vector<int> (101, 0));

int inputR;
int inputC;
int inputK;
int maxRow;
int maxCol;

bool compare(pair<int, int> one, pair<int, int> two) {
    if (one.second == two.second) {
        return one.first < two.first;
    }

    return one.second < two.second;
}

void rOperate() {
    int row = 0;
    for (int i = 0; i < 101; i++) {
        // 행 하나씩 보고 빈도수 구하기
        unordered_map<int, int> freq;

        for (int j = 0; j < 101; j++) {
            int num = oriBoard[i][j];
            if (num == 0) continue;
            freq[num]++;
        }

        // 구한 빈도수 대로 정렬해서 새로운 배열 만들기
        vector<pair<int, int>> sortedFreq(freq.begin(), freq.end());
        sort(sortedFreq.begin(), sortedFreq.end(), compare);
        int size = sortedFreq.size() * 2;

        maxRow = max(row, size);
        row = maxRow;
        //maxRow = max(maxRow, size); // 가장 긴 열 길이 구하기 
        maxRow = min(maxRow, 100); // 100 넘지 않도록 처리

        // 행 초기화
        for (int j = 0; j < 101; j++) {
            oriBoard[i][j] = 0;
        }

        for (int j = 0; j < size; j++) {
            if (j % 2 == 0) {
                oriBoard[i][j] = sortedFreq[j / 2].first;
            } else {
                oriBoard[i][j] = sortedFreq[j / 2].second;
            }
        }
    }
}


void cOperate() {
    int col = 0;
    for (int j = 0; j < 101; j++) {
        // 열 하나씩 보고 빈도수 구하기
        unordered_map<int, int> freq;

        for (int i = 0; i < 101; i++) {
            int num = oriBoard[i][j];
            if (num == 0) continue;
            freq[num]++;
        }

        // 구한 빈도수 대로 정렬해서 새로운 배열 만들기
        vector<pair<int, int>> sortedFreq(freq.begin(), freq.end());
        sort(sortedFreq.begin(), sortedFreq.end(), compare);
        int size = sortedFreq.size() * 2;
        maxCol = max(col, size);
        col = maxCol;
        //maxCol = max(maxCol, size); // 가장 긴 열 길이 구하기 
        maxCol = min(maxCol, 100); // 100 넘지 않도록 처리

        // 열 초기화
        for (int i = 0; i < 101; i++) {
            oriBoard[i][j] = 0;
        }

        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                oriBoard[i][j] = sortedFreq[i / 2].first;
            } else {
                oriBoard[i][j] = sortedFreq[i / 2].second;
            }
        }
    }
}

int main(void) {
    cin >> inputR >> inputC >> inputK;

    // 초기 배열 세팅
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> oriBoard[i][j];
        }
    }

    maxRow = 3;
    maxCol = 3;

    int t;

    for (t = 0; t <= 100; t++) {
        //cout << "t : " << t << "\n";
        if (oriBoard[inputR - 1][inputC - 1] == inputK) {
            break;
        }

        // R연산
        if (maxCol >= maxRow) {
            //cout << "R operation... \n";
            rOperate();
            
            // cout << "maxRow : " << maxRow << "\n";
            // for (int i = 0; i < maxCol; i++) {
            //     for (int j = 0; j < maxRow; j++) {
            //         cout << oriBoard[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
        } 
        
        // C연산
        else {
            //cout << "C operation...\n";
            cOperate();

            // cout << "maxCol : " << maxCol << "\n";
            // for (int i = 0; i < maxCol; i++) {
            //     for (int j = 0; j < maxRow; j++) {
            //         cout << oriBoard[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
        }
    }

    if (t == 101) {
        cout << "-1\n";
    } else {
        cout << t << "\n";
    }

    return 0;
}