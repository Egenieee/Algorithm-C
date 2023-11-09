#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> subBelt;

int solution(vector<int> order) {
    int answer = 0;
    
    int deliveryIdx = 0;
    int current = 1;
    
    while(current != order.size() + 1) {
        subBelt.push(current);
        
        while(!subBelt.empty() && subBelt.top() == order[deliveryIdx]) {
            answer++;
            deliveryIdx++;
            subBelt.pop();
        }
        
        current++;
    }
    
    return answer;
}