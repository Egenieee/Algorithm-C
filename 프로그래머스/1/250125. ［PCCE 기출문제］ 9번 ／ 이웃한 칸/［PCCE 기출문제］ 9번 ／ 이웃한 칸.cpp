#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    string center = board[h][w];
    int boardSize = board.size();
    
    for (int dir = 0; dir < 4; dir++) {
        int ny = h + dy[dir];
        int nx = w + dx[dir];
        
        if (ny < 0 || ny >= boardSize || nx < 0 || nx >= boardSize) continue;
        if (board[ny][nx] == center) answer++;
    }
    
    return answer;
}