#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int dist[1000][1000];
int N, M;
queue<pair<int, int>> Q;

pair<int, int> dirs[4] {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    fill(&dist[0][0], &dist[N][M], -1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                Q.push({ i, j });
                dist[i][j] = 0;
            }
            else if (board[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();

        for (auto nxt : dirs) {
            auto [nxt_x, nxt_y] = pair { nxt.first + x, nxt.second + y };

            // going outside
            if (nxt_x < 0 || nxt_x >= N || nxt_y < 0 || nxt_y >= M)
                continue;

            // unreachable
            if (board[nxt_x][nxt_y] == 0)
                continue;

            // visited
            if (dist[nxt_x][nxt_y] != -1)
                continue;

            dist[nxt_x][nxt_y] = dist[x][y] + 1;
            Q.push({ nxt_x, nxt_y });
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
