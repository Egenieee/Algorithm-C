#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, int> chol;
unordered_map<int, int> bro;

int solution(vector<int> topping) {
    int answer = 0;
    
    for (int i = 0; i < topping.size(); i++) {
        chol[topping[i]]++;
    }
    
    for (int i = 0; i < topping.size(); i++) {
        chol[topping[i]]--;
        
        if (chol[topping[i]] == 0) {
            chol.erase(topping[i]);
        }
        
        bro[topping[i]]++;
        
        if (chol.size() == bro.size()) {
            answer++;
        }
    }
    
    return answer;
}