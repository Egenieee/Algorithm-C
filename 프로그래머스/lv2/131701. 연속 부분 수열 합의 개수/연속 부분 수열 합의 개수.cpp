#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int sizeOfElements = elements.size();
    set<int> sumOfElements;
    
    for (int i = 0; i < sizeOfElements; i++) {
        int len = i + 1;
        
        for (int j = 0; j < sizeOfElements; j ++) {
            int sum = 0;
            
            for (int k = j; k < j + len; k++) {
                sum += elements[k % sizeOfElements];
            }
            
            sumOfElements.insert(sum);
        }
    }
    
    return sumOfElements.size();
}
