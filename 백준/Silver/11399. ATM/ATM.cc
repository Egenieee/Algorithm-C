#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inputN;

vector<pair<int, int>> people;

bool compare(pair<int, int> one, pair<int, int> two) {
    if (one.second == two.second) {
        return one.first < two.first;
    }

    return one.second < two.second;
}

int main() {
    cin >> inputN;

    for (int i = 0; i < inputN; i++) {
        int time;
        cin >> time;
        people.push_back({i, time});
    }

    sort(people.begin(), people.end(), compare);
    
    int prev = people[0].second;
    int sum = prev;

    for (int i = 1; i < inputN; i++) {
        prev += people[i].second;
        sum += prev;
    }

    cout << sum;

    return 0;
}