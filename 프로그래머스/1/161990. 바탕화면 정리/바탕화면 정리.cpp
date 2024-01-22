#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// max_x, min_x
// max_y, min_y 찾아서
// min_x, min_y, max_x, max_y 순으로 반환

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4);
    
    int max_x = -99;
    int min_x = 99;
    int max_y = -99;
    int min_y = 99;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].length(); j++) {
            if(wallpaper[i][j] != '#') continue;
            
            max_y = max(max_y, j);
            min_y = min(min_y, j);
            max_x = max(max_x, i);
            min_x = min(min_x, i);
            
        }
    }
    
    answer[0] = min_x;
    answer[1] = min_y;
    answer[2] = max_x + 1;
    answer[3] = max_y + 1;
    
    return answer;
}