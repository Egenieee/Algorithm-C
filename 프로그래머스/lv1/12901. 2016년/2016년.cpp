#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> daysForMonths = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int sumOfDays = 0;
    
    for (int i = 0; i < a - 1; i++) {
        sumOfDays += daysForMonths[i];    
    }
    
    sumOfDays += b;
    
    int order = sumOfDays % 7 - 1;
    
    if (order == -1) {
        order = 6;
    }
    
    return days[order];
}