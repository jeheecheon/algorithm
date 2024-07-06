#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

pair<int, int> dirs[4] = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main(void)
{
    cin.tie(nullptr)->sync_with_stdio(false);

    string board[5];
    for (string& row : board)
        cin >> row;

    bool mask[25] = {};
    fill(mask + 7, mask + 25, true);

    int ans = 0;
    do {
        bool canGoTo[5][5] = {}, visited[5][5] = {};
        queue<pair<int, int>> Q;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                int offset = i + j * 5;

                // 소문난 7공주
                if (!mask[offset]) {
                    canGoTo[i][j] = true;

                    if (Q.empty()) {
                        Q.push({ i, j });
                        visited[i][j] = true;
                    }
                }
            }
        }

        // adjacent, lee da som
        int adj = 0, lds = 0;

        while (!Q.empty()) {
            auto [r, c] = Q.front();
            Q.pop();

            ++adj;
            lds += board[r][c] == 'S';

            for (auto nxtDir : dirs) {
                auto [rOffset, cOffset] = nxtDir;
                auto [nR, nC] = pair { r + rOffset, c + cOffset };

                if (nR < 0 || nR > 4 || nC < 0 || nC > 4
                    || visited[nR][nC] || !canGoTo[nR][nC]) {
                    continue;
                }

                Q.push({ nR, nC });
                visited[nR][nC] = true;
            }
        }

        ans += (adj >= 7 && lds >= 4);
    } while (next_permutation(mask, mask + 25));

    cout << ans;
}