#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define CODE 0
#define DATE 1
#define MAXIMUM 2
#define REMAIN 3

int sortNumber;
int extractNumber;

// 벡터 두개를 특정 기준에 따라 오름차순 정렬
bool compare(vector<int> &one, vector<int> &two) {
    return one[sortNumber] < two[sortNumber];
}

int getNumber(string standard) {
    if (standard == "code") {
        return 0;
    } else if (standard == "date") {
        return 1;
    } else if (standard == "maximum") {
        return 2;
    } 
    
    return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    extractNumber = getNumber(ext);
    sortNumber = getNumber(sort_by);
    
    // 데이터 추출 기준에 맞춰 값 뽑기
    for (int i = 0; i < data.size(); i++) {
        if (data[i][extractNumber] < val_ext) {
            answer.push_back({data[i][0], data[i][1], data[i][2], data[i][3]});
        }
    }
    
    // 값 정렬
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}