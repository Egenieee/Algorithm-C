#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	char word[5] = "UCPC";
	int now = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == word[now]) {
			now++;
			if (now == 4) {
				cout << "I love UCPC";
				break;
			}
		}
	}

	if (now != 4) cout << "I hate UCPC";
}