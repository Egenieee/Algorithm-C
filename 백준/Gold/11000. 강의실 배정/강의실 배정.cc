#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct qCompare {
    bool operator()(pair<int, int> one, pair<int, int> two) {
        if (one.second == two.second) {
            return one.first > two.first;
        }

        return one.second > two.second;
    }
};

bool compare(pair<int, int> one, pair<int, int> two) {
    if (one.first == two.first) {
        return one.second < two.second;
    }

    return one.first < two.first;
}

vector<pair<int, int>> times;
priority_queue<pair<int, int>, vector<pair<int, int>>, qCompare> myQ;

int inputN;

int main() {
    cin >> inputN;
    int start, end;

    for (int i = 0; i < inputN; i++) {
        cin >> start >> end;

        times.push_back({ start, end });
    }

    sort(times.begin(), times.end(), compare);

    for (int i = 0; i < inputN; i++) {
        int start = times[i].first;
        int end = times[i].second;

        if (myQ.empty()) {
            myQ.push({ start, end });
            continue;
        }

        if (myQ.top().second <= start) {
            myQ.pop();
        }

        myQ.push({ start, end });
    }

    cout << myQ.size();

    return 0;
}