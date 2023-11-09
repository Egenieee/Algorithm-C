#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 101

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int inputN;
int inputM;

int dist[MAX][MAX];
queue<pair<int, int>> mQueue;

void init(int n, int m) {
    inputN = n;
    inputM = m;
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = -1;
        }
    }
    
    mQueue.push({0, 0});
    dist[0][0] = 1;
}

int solution(vector<vector<int> > maps){    
    init(maps.size(), maps[0].size());
    
    while(!mQueue.empty()) {
        pair<int, int> currentPos = mQueue.front();
        mQueue.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int ny = currentPos.first + dy[dir];
            int nx = currentPos.second + dx[dir];
            
            if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputM) continue;
            
            if (dist[ny][nx] >= 0 || maps[ny][nx] == 0) continue;
            
            dist[ny][nx] = dist[currentPos.first][currentPos.second] + 1;
            mQueue.push({ny, nx});
        }
    }
    
    return dist[inputN - 1][inputM - 1];
}