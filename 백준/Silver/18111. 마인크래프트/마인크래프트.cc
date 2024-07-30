#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, B;
    cin >> N >> M >> B;
    
    vector<vector<int>> board(N, vector<int>(M));
    int lowest = 256, highest = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            lowest = min(lowest, board[i][j]);
            highest = max(highest, board[i][j]);
        }
    }

    pair<int, int> ans = {0x7fffffff, -1};
    
    for (int h = lowest; h <= highest; ++h) {
        int curB = B;
        int time = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int diff = board[i][j] - h;
                if (diff > 0) {
                    time += diff * 2;
                    curB += diff;
                } else {
                    time -= diff;
                    curB += diff;
                }
            }
        }

        if (curB >= 0 && time <= ans.first) {
            ans = {time, h};
        }
    }

    cout << ans.first << ' ' << ans.second;
}
