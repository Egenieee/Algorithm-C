#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int visited[20] = {0};
    int answer = 0;
    
    int pointer = 0;
    int checkCnt = name.size();
    int moveCnt = checkCnt - 1;
    
    for (int i = 0; i < checkCnt; i++) {
        answer += min('Z' - name[i] + 1, name[i] - 'A');
        
        int next = i + 1;
        while(next < checkCnt && name[next] == 'A') {
            next++;
        }
        int a = i * 2 + (checkCnt - next);
        int b = i + (checkCnt - next) * 2;
        moveCnt = min(moveCnt, min(a, b));
    }
    
    answer += moveCnt;
    
    return answer;
}