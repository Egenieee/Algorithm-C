#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int inputN;

int main(void) {
    cin >> inputN;

    priority_queue<int, vector<int>, greater<int>> cards;

    for (int i = 0; i < inputN; i++) {
        int card;
        cin >> card;
        cards.push(card);
    }

    int sum = 0;

    int first;
    int second;
    int tempSum;

    while(cards.size() > 1) {
        first = cards.top();
        cards.pop();

        second = cards.top();
        cards.pop();

        tempSum = first + second;

        sum += tempSum;
        cards.push(tempSum);
    }

    cout << sum << "\n";

    return 0;
}