#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int level;
int maxCnt = 0;
int taken[8];

void dfs(int curCnt, int curPirodo, vector<vector<int>> &dungeons) {
    
    maxCnt = max(curCnt, maxCnt); 
        
     //cout << "현재 피로도 : " << curPirodo << "\n";
    
    for (int i = 0; i < level; i++) {
        if (taken[i]) continue;
        if (curPirodo < dungeons[i][0]) continue;
        taken[i] = 1;        
        //cout << i + 1 << "번째 던전 간다잇\n";
        dfs(curCnt + 1, curPirodo - dungeons[i][1], dungeons);
        taken[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    level = dungeons.size();
    
    dfs(0, k, dungeons);
    
    return maxCnt;
}