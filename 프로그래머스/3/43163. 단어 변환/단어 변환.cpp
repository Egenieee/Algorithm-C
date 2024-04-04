#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> inputWords;

string inputTarget;
string inputBegin;

int curLevel;
int inputN;
int taken[51];

bool isDifferentOne(string word, string target) {
    int cnt = 0;
    
    for (int i = 0; i < word.size(); i++) {
        if (word[i] != target[i]) {
            cnt++;   
        }
    }
    
    //cout << "cnt : " << cnt << "\n";
    
    if (cnt == 1) {
        return true;
    }
    
    return false;
}

void dfs(string curWord, int level) {
    //cout << "curWord : " << curWord << "\n";
    
    if (curWord == inputTarget) {
        curLevel = level;
        return;
    }
    
    
    
    for (int i = 0; i < inputWords.size(); i++) {
        if (taken[i]) continue;
        if (!isDifferentOne(curWord, inputWords[i])) continue;
        
        taken[i] = 1;
        dfs(inputWords[i], level + 1);
        taken[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    inputWords = words;
    inputN = words.size();
    inputTarget = target;
    inputBegin = begin;
    
    dfs(begin, 0);
    
    return curLevel;
}