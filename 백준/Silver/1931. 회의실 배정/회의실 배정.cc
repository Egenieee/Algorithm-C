#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;

vector<pair<int, int>> meetings;

bool compare(pair<int, int> one, pair<int, int> two) {
    if (one.second == two.second) {
        return one.first < two.first;
    }

    return one.second < two.second;
}

int main() {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        int start, end;
        cin >> start >> end;

        meetings.push_back({start, end});
    }

    sort(meetings.begin(), meetings.end(), compare);

    int end = 0;
    int cnt = 0;

    end = meetings[0].second;
    cnt++;

    for (int i = 1; i < inputN; i++) {
        if (meetings[i].first < end) continue;

        end = meetings[i].second;
        cnt++;
    }

    cout << cnt;

    return 0;
}