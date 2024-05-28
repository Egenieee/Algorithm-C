#include <iostream>
#include <vector>

using namespace std;

string one;
string two;

int dp[1001][1001];

int main() {
    cin >> one >> two;

    for (int i = 1; i < one.size() + 1; i++) {
        for (int j = 1; j < two.size() + 1; j++) {
            if (one[i - 1] == two[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[one.size()][two.size()];

    return 0;
}