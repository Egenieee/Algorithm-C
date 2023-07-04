#include <string>
#include <vector>

using namespace std;

int sumOfList(vector<int> num_list) {
    int sum = 0;
    
    for (int number : num_list) {
        sum += number;
    }
    
    return sum;
}

int multipleOfList(vector<int> num_list) {
    int multiple = 1;
    
    for (int number : num_list) {
        multiple *= number;
    }
    
    return multiple;
}

int solution(vector<int> num_list) {
    
    if (num_list.size() > 10) {
        return sumOfList(num_list);
    }
    
    return multipleOfList(num_list);
}