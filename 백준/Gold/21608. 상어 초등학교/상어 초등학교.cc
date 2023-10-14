#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int inputN;

int board[21][21];
int fav[21][21];
int blank[21][21];

vector<int> favFriends[401];

vector<pair<int, int>> candidates;

bool compare(pair<int, int> one, pair<int, int> two) {

    // 좋아하는 친구가 많은 순으로 소트
    if (fav[one.first][one.second] >= fav[two.first][two.second]) {

        // 좋아하는 친구 수가 같다면, 빈칸 수로 비교
        if (fav[one.first][one.second] == fav[two.first][two.second]) {
            // 빈칸이 많은 순으로 소트
            if (blank[one.first][one.second] >= blank[two.first][two.second]) {
                
                // 빈칸 수도 같다면 
                if (blank[one.first][one.second] == blank[two.first][two.second]) {

                    // 행 값이 작은 순으로 소트
                    if (one.first <= two.first) {

                        // 행 값도 같다면 
                        if (one.first == two.first) {

                            // 열 값이 작은 순으로 소트
                            if (one.second < two.second) {
                                return true;
                            }
                            return false;
                        }

                        return true;
                    }

                    return false;
                }

                return true;
            }

            return false;
        }

        return true;
    }

    return false;
}

void getFavFriendsAndBlack(int curStudent) {

    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            // 이미 누가 자리에 있다면 패스
            if (board[i][j] != 0) continue;

            int numOfFav = 0;
            int numOfBlank = 0;

            // 상하좌우에 좋아하는 학생이 있는 지 확인하기
            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputN) continue;

                // 빈칸이면
                if (board[ny][nx] == 0) {
                    numOfBlank++;
                }

                // 좋아하는 친구가 있다면
                for (int fri = 0; fri < 4; fri++) {
                    if (board[ny][nx] == favFriends[curStudent][fri]) {
                        numOfFav++;
                    }
                }
            }

            // 모든 보드보면서 가능한 부분에 주변에 친구 몇명있고, 빈칸은 몇명있는지 써놓기
            fav[i][j] = numOfFav;
            blank[i][j] = numOfBlank;

            candidates.push_back({i, j});
        }
    }
}

int getSatify() {
    int sumOfFav = 0;
    for (int i = 0; i < inputN; i++) {
        for (int j = 0; j < inputN; j++) {
            int num = board[i][j];
            int numOfFav = 0;

            for (int dir = 0; dir < 4; dir++) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (ny < 0 || ny >= inputN || nx < 0 || nx >= inputN) continue;

                for (int fri = 0; fri < 4; fri++) {
                    if (board[ny][nx] == favFriends[num][fri]) {
                        numOfFav++;
                    }
                }
            }

            if (numOfFav != 0) {
                sumOfFav += pow(10, numOfFav - 1);
            }
        }
    }

    return sumOfFav;
}

int main(void) {
    cin >> inputN;

    for (int n = 0; n < inputN * inputN; n++) {
        int num;

        cin >> num;

        for (int j = 0; j < 4; j++) {
            int fav;
            cin >> fav;
            favFriends[num].push_back(fav);
        }

        // 입력 받은 순서대로 자리 배치하기
        candidates.resize(0);

        // 비어있는 칸 중 상하좌우에 좋아하는 학생의 수와 빈칸 수 구하기
        getFavFriendsAndBlack(num);

        // 소트한 담에 배정
        sort(candidates.begin(), candidates.end(), compare);

        pair<int, int> win = candidates[0];

        board[win.first][win.second] = num;
    }

    cout << getSatify() << "\n";
    
    return 0;
}