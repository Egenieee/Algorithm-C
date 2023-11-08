#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

#define SCORE 4

unordered_map<string, vector<int>> allCases;

vector<string> split(string input, string delimeter) {
    string token;
    vector<string> tokens;
    long long pos;
    
    while((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        tokens.push_back(token);      
        input.erase(0, pos + delimeter.length());
    }
    
    tokens.push_back(input);
    
    return tokens;
}

void saveCases(vector<string> eachInfo) {    
    for (int i = 0; i < 16; i++) {
        string oneCase = "";
        
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) {
                oneCase += eachInfo[j];
            } else {
                oneCase += "-";
            }
        }
        
        allCases[oneCase].push_back(stoi(eachInfo[SCORE]));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    // info -> 가능한 모든 조합 맵에 저장하기
    for (string oneInfo : info) {
        vector<string> eachInfo = split(oneInfo, " ");
        saveCases(eachInfo);
    }
    
    vector<int> answer;
    
    for(auto iter = allCases.begin(); iter != allCases.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }
    
    for (string eachQuery : query) {
        vector<string> queryTokens = split(eachQuery, " ");
        
        // 0, 2, 4, 6번째 토큰으로 쿼리 구하기
        // 7번은 스코어
        string answerQuery = queryTokens[0] + queryTokens[2] + queryTokens[4] + queryTokens[6];
        int score = stoi(queryTokens[7]);
        
        vector<int> targetScores = allCases[answerQuery];
        
        if (targetScores.size() != 0) {
            // lower_bound 정하기
            int idx = lower_bound(targetScores.begin(), targetScores.end(), score) - targetScores.begin();
            answer.push_back(targetScores.size() - idx);
        } else {
            // 벡터 길이 0이라면 0
            answer.push_back(0);
        }
    }
    
    return answer;
}