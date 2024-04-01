#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int board[101][101];

int inputN;
int inputM;

int width;
int height;

int rotate(int y1, int x1, int y2, int x2) {
    int temp = board[y1 + 1][x1];
    int minNum = min(10001, temp);
    
    width = abs(x1 - x2);
    height = abs(y1 - y2);
    
    // 왼쪽 면
    for (int i = y1 + 1; i < y2; i++) {
        board[i][x1] = board[i + 1][x1];
        minNum = min(board[i + 1][x1], minNum);
    }
    
    //아래쪽 면
    for (int i = x1; i < x2; i++) {
        board[y2][i] = board[y2][i + 1];
        minNum = min(board[y2][i + 1], minNum);
    }
    
    // 오른쪽 면
    for (int i = y2; i > y1; i--) {
        board[i][x2] = board[i - 1][x2];
        minNum = min(board[i - 1][x2], minNum);
    }
    
    // 위쪽 면
    for (int i = x2; i > x1; i--) {
        board[y1][i] = board[y1][i - 1];
        minNum = min(board[y1][i - 1], minNum);
    }
    
    board[y1][x1] = temp;
    
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    inputN = rows;
    inputM = columns;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = i * columns + j + 1;
        }
    }
    
    
    for (vector<int> query : queries) {
        int minNum = rotate(query[0] - 1, query[1] - 1, query[2] - 1, query[3] - 1);
        answer.push_back(minNum);
    }
    
    return answer;
}