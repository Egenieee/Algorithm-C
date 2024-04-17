#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

string inputStr;
int maxCnt = 0;
int taken[8];

unordered_set<int> mySet;

bool isPrime(string strNum) {
    if (strNum == "") return false;
    
    int num = stoi(strNum);
    
    if (num == 1 || num == 0) return false;
    
    int dividen = 2;
    
    while(num > dividen) {
        if (num % dividen == 0) return false;
        dividen++;
    }
    
    mySet.insert(num);
    
    return true;
} 

void dfs(string curStr, int cnt) {
    isPrime(curStr);

    for (int i = 0; i < inputStr.size(); i++) {
        if(taken[i]) continue;
        
        taken[i] = 1;
        dfs(curStr + inputStr[i], cnt + 1);
        taken[i] = 0;
    }
}

int solution(string numbers) {
    inputStr = numbers;
    
    dfs("", 0);
    
    return mySet.size();
}