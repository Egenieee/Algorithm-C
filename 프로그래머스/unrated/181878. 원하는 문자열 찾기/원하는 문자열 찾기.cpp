#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    if (myString.size() < pat.size()) {
        return 0;
    }
    
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    
    int answer = 0;
    
    if (myString.find(pat) != string::npos) {
        return 1;
    }
    
    return 0;
}