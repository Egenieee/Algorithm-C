#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> one, pair<int, int> two) {
    if (one.first == two.first) {
        return one.first > two.first;
    }
    
    return one.second > two.second;
}

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> map;
    
    for (int eachTangerine : tangerine) {
        map[eachTangerine]++;
    }
    
    vector<pair<int, int>> sortVec(map.begin(), map.end());
    
    sort(sortVec.begin(), sortVec.end(), compare);
    
    int answer = 0;
    
    for (int i = 0; i < sortVec.size(); i++) {
        if (k <= 0) break;
        
        //cout << sortVec[i].first << "번 귤 " << sortVec[i].second << "개 \n";
        
        answer++;
        k -= sortVec[i].second;
        
        //cout << "현재 k : " << k << "\n";
    }
    
    
    return answer;
}