#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[0].size(); j++) {
            // answer 한 칸 채우기
            // arr1의 한 행과 arr2의 한 열 곱해서 더한 값
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
                //cout << arr1[i][k] << "*" << arr2[k][j] << " = " << arr1[i][k] * arr2[k][j] << "\n";
            }
            //cout << "현재 sum = " << sum << "\n";
            answer[i][j] = sum;
        }
    }
    
    return answer;
}