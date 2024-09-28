// baekjoon 2636

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    bool board[101][101];

    int cnt = 0; // 치즈수
    point entry;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j])
                ++cnt;
            if ((i == 0 || i == N - 1 || j == 0 || j == M - 1) && board[i][j] == false)
                entry = { i, j };
        }
    }

    int prevCnt = cnt;
    int days = 0;
    while (cnt) {
        ++days;
        prevCnt = cnt;

        vector<vector<bool>> vis(N, vector<bool>(M, false));
        queue<point> Q;
        Q.push(entry);

        while (!Q.empty()) {
            auto [cx, cy] = Q.front();
            Q.pop();

            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = point { cx + dx, cy + dy };

                if (nx < 0 || nx >= N || ny < 0 || ny >= M
                    || vis[nx][ny])
                    continue;

                vis[nx][ny] = true;

                if (board[nx][ny]) {
                    board[nx][ny] = 0;
                    continue;
                }

                Q.push({ nx, ny });
            }
        }

        cnt = 0;
        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < M; ++j) 
                if (board[i][j])
                    ++cnt;
    }

    cout << days << endl << prevCnt;
}