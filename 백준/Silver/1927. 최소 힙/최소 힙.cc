#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(long long one, long long two) {
        return one > two;
    }
};

int inputN;
priority_queue<long long, vector<long long>, compare> myQ;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> inputN;
    
    long long x;

    for (int i = 0; i < inputN; i++) {
        cin >> x;

        if (x == 0) {
            if (myQ.empty()) {
                cout << 0;
            } else {
                int result = myQ.top();
                cout << result;
                myQ.pop();
            }
            cout << "\n";
        } else {
            myQ.push(x);
        }
    }

    return 0;
}