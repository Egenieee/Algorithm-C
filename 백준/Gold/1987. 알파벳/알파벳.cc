#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int inputR;
int inputC;
int maxLength;

char board[20][20];
bool visited[20][20];
int hasAlphabet[26];

vector<char> footPrint;

bool isDuplicate() {
    char target = footPrint[footPrint.size() - 1];

    for (int i = 0; i < footPrint.size() - 1; i++) {
        if (footPrint[i] == target) return true;
    }

    return false;
}

void dfs(int y, int x) {
    // 모든 칸을 지날 수 있는 경우
    if (footPrint.size() == inputR * inputC) {
        maxLength = inputR * inputC;
        return;
    }

    // 기존 알파벳을 다시 만난 경우 리턴
    if (isDuplicate()) {
        int size = footPrint.size() - 1;

        if (maxLength < size) {
            maxLength = size;
        }

        return;
    }

    // 4방향 모두 보면서 이동하기
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= inputR || nx < 0 || nx >= inputC) continue;

        if (visited[ny][nx]) continue;

        // 한 칸 이동
        visited[ny][nx] = true;
        footPrint.push_back(board[ny][nx]);

        // dfs
        dfs(ny, nx);

        // 원복
        visited[ny][nx] = false;
        footPrint.pop_back();
    }

}

int main(void) {
    cin >> inputR >> inputC;
    maxLength = -1;
    footPrint.clear();
    
    for (int i = 0; i < inputR; i++) {
        string oneLine;
        cin >> oneLine;
        
        for (int j = 0; j < inputC; j++) {
            board[i][j] = oneLine[j];   
            visited[i][j] = false; 
        }
    }
    
    footPrint.push_back(board[0][0]);
    visited[0][0] = true;

    dfs(0, 0);
    
    cout << maxLength << "\n";

    return 0;
}