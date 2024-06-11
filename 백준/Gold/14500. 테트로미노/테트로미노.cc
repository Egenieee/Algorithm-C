#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct block {
    vector<vector<int>> eachBlock;
};

int inputN, inputM;

int board[501][501];
vector<block> blocks(19);

void init() {
    blocks[0].eachBlock = {{1, 1, 1, 1}};
    blocks[1].eachBlock = {{1}, {1}, {1}, {1}};
    blocks[2].eachBlock = {{1, 0}, {1, 0}, {1, 1}};
    blocks[3].eachBlock = {{0, 1}, {0, 1}, {1, 1}};
    blocks[4].eachBlock = {{1, 1}, {1, 0}, {1, 0}};
    blocks[5].eachBlock = {{1, 1}, {0, 1}, {0, 1}};
    blocks[6].eachBlock = {{1, 0, 0}, {1, 1, 1}};
    blocks[7].eachBlock = {{0, 0, 1}, {1, 1, 1}};
    blocks[8].eachBlock = {{1, 1}, {1, 1}};
    blocks[9].eachBlock = {{1, 1, 1}, {1, 0, 0}};
    blocks[10].eachBlock = {{1, 1, 1}, {0, 0, 1}};
    blocks[11].eachBlock = {{1, 0}, {1, 1}, {1, 0}};
    blocks[12].eachBlock = {{0, 1}, {1, 1}, {0, 1}};
    blocks[13].eachBlock = {{1, 0}, {1, 1}, {0, 1}};
    blocks[14].eachBlock = {{0, 1}, {1, 1}, {1, 0}};
    blocks[15].eachBlock = {{1, 1, 0}, {0, 1, 1}};
    blocks[16].eachBlock = {{0, 1, 1}, {1, 1, 0}};
    blocks[17].eachBlock = {{1, 1, 1}, {0, 1, 0}};
    blocks[18].eachBlock = {{0, 1, 0}, {1, 1, 1}};
}

int main() {
    cin >> inputN >> inputM;

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            cin >> board[i][j];
        }
    }

    init();

    int maxValue = 0;

    // block 하나씩 board에 맞춰가면서 합 구하기
    for (block element : blocks) {
        // for (int i = 0; i < element.eachBlock.size(); i++) {
        //     for (int j = 0; j < element.eachBlock[0].size(); j++) {
        //         cout << element.eachBlock[i][j];
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        int sum = 0;
        int rowSize = element.eachBlock.size();
        int colSize = element.eachBlock[0].size();

        for (int i = 0; i <= inputN - rowSize; i++) {
            for (int j = 0; j <= inputM - colSize; j++) {
                sum = 0;
                
                for (int y = 0; y < rowSize; y++) {
                    for (int x = 0; x < colSize; x++) {
                        if (element.eachBlock[y][x] != 1) continue;
                        sum += board[i + y][j + x];
                    }
                }

                maxValue = max(maxValue, sum);
            }
        }
    }

    cout << maxValue;

    return 0;
}