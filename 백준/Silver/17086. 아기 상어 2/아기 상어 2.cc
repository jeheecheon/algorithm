// baekjoon 17086

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

pair<int, int> dirs[] = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 },
    { -1, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> Q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({ i, j });
                dist[i][j] = 0;
            }
        }
    }

    int ans = 0;
    while (!Q.empty()) {
        auto [curX, curY] = Q.front();
        Q.pop();

        for (auto [dirX, dirY] : dirs) {
            auto [nextX, nextY] = make_pair(dirX + curX, dirY + curY);

            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;
            if (dist[nextX][nextY] != -1)
                continue;

            dist[nextX][nextY] = dist[curX][curY] + 1;
            ans = max(ans, dist[nextX][nextY]);
            Q.push({ nextX, nextY });
        }
    }

    cout << ans;
}
