#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int hangTime = 0;
int recommendCount[102];
int times[102];

void eraseOldestPhoto(vector<int> &students) {
    // 1. 추천 수가 가장 적은 학생 삭제
    // 2. 추천 수가 가장 적은 학생이 두명이라면 time 값 비교해서 더 작은 값 삭제

    int minOfRecommend = 1002;
    vector<int> indexToRemove; 

    // 최솟값 찾기
    for (int student : students) {
        minOfRecommend = min(minOfRecommend, recommendCount[student]);
    }

    // 최솟값과 같은 추천수 가지고 있는 학생 뽑기
    for (int student : students) {
        if (minOfRecommend == recommendCount[student]) {
            indexToRemove.push_back(student);
        }
    }

    int minTime = 1002;
    int studentToRemove;

    for (int student : indexToRemove) {
        if (times[student] < minTime) {
            minTime = times[student];
            studentToRemove = student;
        }
    }

    students.erase(remove(students.begin(), students.end(), studentToRemove), students.end());

    return;
}

int main(void) {
    int n;
    int r;

    cin >> n >> r;

    int recommends[r];

    for (int i = 0; i < r; i++) {
        string student;
        cin >> student;
        recommends[i] = atoi(student.c_str());
    }

    vector<int> students;

    for (int recommend : recommends) {
        // 후보에 추천받은 학생이 있는 지 확인
        if (count(students.begin(), students.end(), recommend)) {
            recommendCount[recommend]++;
            continue;
        } 

        if (students.size() == n) {
            // 꽉 찼다면 학생 삭제
            eraseOldestPhoto(students);
        } 

        students.push_back(recommend);
        recommendCount[recommend] = 1;
        times[recommend] = hangTime;

        hangTime++;

        // cout << "-------------" << recommend << "번째 추천 순서--------------\n";

        // for (auto student : students) {
        //     cout << student << "번 학생의 추천수는 " << recommendCount[student] <<"번 이며, 최초 게시 시간은 " << times[student] << "입니다\n";
        // }

        // cout << "----------------------------------------\n";
    }

    sort(students.begin(), students.end());

    for (auto student : students) {
        cout << student << " ";
    }
}

// 5
// 20
// 1 100 49 32 43 53 59 59 60 60 70 81 1 2 3 4 1 2 4 5 