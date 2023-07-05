#include <string>
#include <vector>

using namespace std;

string solution(string s) {    
    bool isFirstAlphabet = true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isFirstAlphabet = true;
            continue;
        }
        
        if (isFirstAlphabet) {
            // 대문자로 변경
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
            
            isFirstAlphabet = false;
            
        } else {
            // 모두 소문자로 변경
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return s;
}