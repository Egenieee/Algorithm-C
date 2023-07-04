#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (string oneLine : picture) {
        string str = "";
        
        for (int i = 0; i < oneLine.size(); i++) {
            char currentChar = oneLine[i];
            
            for (int j = 0; j < k; j++) {
                str += currentChar;
            }
        }

        for (int m = 0; m < k; m++) {
            answer.push_back(str);
        }
    }
    
    return answer;
}