#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int board[101][101];
int visited[101][101];
int inputN, inputM;

vector<int> answer;

void bfs(int y, int x) {
    queue<pair<int, int>> myQ;
    visited[y][x] = 1;
    myQ.push({y, x});
    int sum = board[y][x];
    
    while(!myQ.empty()) {
        int curY = myQ.front().first;
        int curX = myQ.front().second;
        myQ.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            
            if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;
            if (visited[ny][nx] || board[ny][nx] < 0) continue;
            
            sum += board[ny][nx];
            visited[ny][nx] = 1;
            myQ.push({ny, nx});
        }
    }
    
    answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {
    
    inputN = maps.size();
    inputM = maps[0].size();
    
    for (int i= 0 ;i < inputN; i++) {
        for (int j= 0; j < inputM; j++) {
            if (maps[i][j] == 'X') {
                board[i][j] = -1;
            } else {
                board[i][j] = maps[i][j] - '0';
            }
        }
    }
    
    for (int i= 0; i < inputN; i++) {
        for (int j = 0; j < inputM; j++) {
            if (board[i][j] > 0) {
                if (visited[i][j]) continue;
                bfs(i, j);
            }
        }
    }
    
    if (answer.size() == 0) {
        answer.push_back(-1);
        return answer;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}