#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;
int inputM;
int truthCnt;

int parents[51];
int truths[51];
vector<int> parties[51];

void init() {
    for (int i = 0; i < 51; i++) {
        parents[i] = i;
    }
}

int find(int target) {
    if (parents[target] == target) return target;

    int ret = find(parents[target]);
    parents[target] = ret;

    return ret;
}

void setUnion(int one, int two) {
    int bossOne = find(one);
    int bossTwo = find(two);

    if (bossOne == bossTwo) return;

    parents[bossTwo] = bossOne;
}

// 파티에 온사람의 boss가 진실을 아는 사람이라면 true 반환
bool isTruthPerson(int partyPerson) {
    int boss = parents[partyPerson];

    for (int i = 0; i < truthCnt; i++) {
        if (boss == truths[i]) return true;
    }

    return false;
}

int main() {
    cin >> inputN >> inputM;

    int incomeCnt;
    cin >> truthCnt;

    for(int i = 0; i < truthCnt; i++) {
        cin >> truths[i];
    }

    init();

    for (int i = 0; i < inputM; i++) {
        cin >> incomeCnt;

        if (incomeCnt > 1) {
            vector<int> people;

            for (int j = 0; j < incomeCnt; j++) {
                int person;
                cin >> person;
                people.push_back(person);
                parties[i].push_back(person);
            }

            sort(people.begin(), people.end());

            // 입력받은 모든 사람끼리 이어주기
            for (int one = 0; one < incomeCnt; one++) {
                for (int two = one + 1; two < incomeCnt; two++) {
                    setUnion(people[one], people[two]);
                }
            }
        } else {
            int person;
            cin >> person;
            parties[i].push_back(person);
        }
    }

    for (int i = 0; i <= inputN; i++) {
        find(i);
    }

    int cnt = inputM;

    // 진실을 아는 사람이 네트워크를 만들었을 경우 boss가 바뀔 수 있기 때문에 
    // 진실을 아는 사람을 해당 네트워크의 boss로 바꿔줌
    for (int i = 0; i < truthCnt; i++) {
        int person = truths[i];
        truths[i] = parents[person];
    }

    // 파티에 온 명단 다시 살펴보면서 boss확인하기
    for (int i = 0; i < inputM; i++) {
        bool found = false;

        for (int j = 0; j < parties[i].size(); j++) {
            int partyPerson = parties[i][j];

            if (isTruthPerson(partyPerson)) {
                found = true;
                continue;
            }
        }

        if (found) {
            cnt--;
        }
    }

    cout << cnt;

    return 0;
}