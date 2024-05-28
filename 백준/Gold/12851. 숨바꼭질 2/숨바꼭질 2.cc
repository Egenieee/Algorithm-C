#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
    int time;
    int cnt;
};

int inputN, inputX;

info infos[100001];

void init() {
    for (int i = 0; i < 100001; i++) {
        infos[i].time = 987654321;
    }
}

void bfs() {
    init();

    queue<int> myQ;
    infos[inputN].time = 0;
    infos[inputN].cnt = 1;
    myQ.push({inputN});

    while(!myQ.empty()) {
        int curNode = myQ.front();
        myQ.pop();

        if (curNode - 1 >= 0) {
            if (infos[curNode - 1].time >= infos[curNode].time + 1) {
                infos[curNode - 1].time = infos[curNode].time + 1;
                infos[curNode - 1].cnt++;

                myQ.push(curNode - 1);
            }
        }
        
        if (curNode + 1 <= 100000) {
            if (infos[curNode + 1].time >= infos[curNode].time + 1) {
                infos[curNode + 1].time = infos[curNode].time + 1;
                infos[curNode + 1].cnt++;

                myQ.push(curNode + 1);
            }
        }

        if (curNode * 2 <= 100000) {
            if (infos[curNode * 2].time >= infos[curNode].time + 1) {
                infos[curNode * 2].time = infos[curNode].time + 1;
                infos[curNode * 2].cnt++;

                myQ.push(curNode * 2);
            }
        }
    }
}

int main() {
    cin >> inputN >> inputX;

    bfs();

    cout << infos[inputX].time << "\n" << infos[inputX].cnt;

    return 0;
}