#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> myMap;

string inputSkill;
int skillDAT[26];

void getValidOrder() {
    for (int i = 1; i <= inputSkill.size(); i++) {
        string temp = inputSkill.substr(0, i);
        myMap.push_back(temp);
    }
}

bool isValidSkillTree(string skillTree) {
    // skill에 해당하는 글자만 남기고 나머지 모두 삭제하기
    vector<int> idx;
    
    for (int i = 0; i < skillTree.size(); i++) {
        if (skillDAT[skillTree[i] - 'A'] == 1) {
            idx.push_back(i);
        }
    }
    
    string newStr;
    for (int i = 0; i < idx.size(); i++) {
        newStr += skillTree[idx[i]];
    }
    
    // 스킬이 없는 경우도 가능한 경우
    if (newStr == "") {
        return true;
    }
    
    // skill로 만들 수 있는 모든 부분 문자열 중에 해당 글자가 있는지 확인하기
    for (string word : myMap) {
        if (word == newStr) {
            return true;
        }
    }
    
    return false;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    inputSkill = skill;
    
    for (int i = 0; i < skill.size(); i++) {
        skillDAT[skill[i] - 'A']++;
    }
    
    getValidOrder();
    
    for (string skillTree : skill_trees) {
        if (isValidSkillTree(skillTree)) {
            answer++;
        }
    }
    
    return answer;
}