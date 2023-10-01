#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int price;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    int count = 0;
    
    cin >> n >> price;
    
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end(), compare);
    
    for (int i = 0; i < n; i++) {
        if (price < coins[i]) continue;
        
        count += price / coins[i];
        
        price = price % coins[i];
    }
    
    cout << count << "\n";
    
    return 0;
}