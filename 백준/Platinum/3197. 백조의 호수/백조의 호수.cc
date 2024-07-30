#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;

pair<int, int> dirs[4] = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    string board[R];
    pair<int, int> birds[2];
    int b = 0;

    queue<pair<int, int>> waterQueue;
    vector<vector<int>> waterDist(R, vector<int>(C, -1));
    for (int i = 0; i < R; ++i) {
        cin >> board[i];

        for (int j = 0; j < C; ++j) {
            if (board[i][j] == 'L')
                birds[b++] = { i, j };
            if (board[i][j] != 'X') {
                waterQueue.push({ i, j });
                waterDist[i][j] = 0;
            }
        }
    }

    while (!waterQueue.empty()) {
        auto [curR, curC] = waterQueue.front();
        waterQueue.pop();

        for (auto [dirR, dirC] : dirs) {
            auto [destR, destC] = pair { curR + dirR, curC + dirC };

            if (destR < 0 || destR >= R || destC < 0 || destC >= C
                || board[destR][destC] != 'X'
                || waterDist[destR][destC] != -1)
                continue;

            waterDist[destR][destC] = waterDist[curR][curC] + 1;
            waterQueue.push({ destR, destC });
        }
    }

    queue<pair<int, int>> birdQueue;
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vis[birds[0].first][birds[0].second] = true;
    birdQueue.push(birds[0]);

    int ans = 0;
    while (true) {
        queue<pair<int, int>> nextBirdQueue;

        while (!birdQueue.empty()) {
            auto [curR, curC] = birdQueue.front();
            birdQueue.pop();

            if (curR == birds[1].first && curC == birds[1].second) {
                cout << ans;
                return 0;
            }

            for (auto [dirR, dirC] : dirs) {
                auto [destR, destC] = pair { curR + dirR, curC + dirC };

                if (destR < 0 || destR >= R || destC < 0 || destC >= C
                    || vis[destR][destC])
                    continue;

                if (waterDist[destR][destC] <= ans) {
                    vis[destR][destC] = true;
                    birdQueue.push({ destR, destC });
                } else {
                    vis[destR][destC] = true;
                    nextBirdQueue.push({ destR, destC });
                }
            }
        }
        ++ans;

        birdQueue = move(nextBirdQueue);
    }
}
