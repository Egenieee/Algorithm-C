#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main(void) {
    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {
        cin >> inputN;

        vector<pair<int, int>> emp(inputN);

        for (int i = 0; i < inputN; i++) {
            cin >> emp[i].first >> emp[i].second;
        }

        sort(emp.begin(), emp.end(), compare);

        int remove = 0;
        int topIdx = 0;
        int curIdx = 1;

        while(curIdx != emp.size()) {
            if (emp[topIdx].second < emp[curIdx].second) {
                remove++;
            } else {
                topIdx = curIdx;
            }
            curIdx++;
        }

        cout << inputN - remove << "\n";

    }

    return 0;
}