#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;
vector<int> arr;

bool isStop() {
    for (int i = 0; i < inputN; i++) {
        if (arr[i] != 0) return false;
    }

    return true;
}

int main() {

    cin >> inputN;
    arr.resize(inputN);

    for (int i = 0; i < inputN ;i++) {
        cin >> arr[i];
    }

    int time = 0;
    bool stop = false;

    while(true) {
        sort(arr.begin(), arr.end(), greater<int>());

        if (arr[0] == 0) {
            break;
        }

        for (int i = 0; i < 2; i++) {
            if (arr[i] == 0) continue;

            arr[i]--;
        }

        time++;
    }

    if (time > 1440) {
        cout << -1;
    } else {
        cout << time;
    }

    return 0;
}