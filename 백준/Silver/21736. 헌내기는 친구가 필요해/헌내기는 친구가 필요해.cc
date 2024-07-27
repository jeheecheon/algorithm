#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> dirs[] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin >> N >> M;
    string board[N];

    queue<pair<int, int>> Q;
    vector<vector<bool>> vis = vector(N, vector(M, false));

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
        for (int j = 0; j < board[i].length(); ++j) {
            if (board[i][j] == 'I') {
                Q.push({ i, j });
                vis[i][j] = 1;
            }
        }
    }

    int ans = 0;
    while (!Q.empty()) {
        auto [curX, curY] = Q.front();
        Q.pop();

        for (auto [dirX, dirY] : dirs) {
            auto [destX, destY] = pair { curX + dirX, curY + dirY };

            if (destX < 0 || destX >= N || destY < 0 || destY >= M
                || vis[destX][destY]
                || board[destX][destY] == 'X')
                continue;

            if (board[destX][destY] == 'P')
                ++ans;

            vis[destX][destY] = true;
            Q.push({ destX, destY });
        }
    }

    cout << (ans == 0 ? "TT" : to_string(ans));
}