#include <algorithm>
#include <iostream>
using namespace std;

string board[5];
int R, C, K;
pair<int, int> dirs[4] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
int dist[5][5];
int cnt = 0;

void solve(int x, int y)
{
    if (dist[x][y] > K) {
        return;
    }
    if (x == 0 && y == C - 1) {
        if (dist[x][y] == K) 
            ++cnt;
        return;
    }

    for (auto [dirX, dirY] : dirs) {
        auto [nextX, nextY] = pair { dirX + x, dirY + y };

        if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C)
            continue;
        if (dist[nextX][nextY] >= 0 || board[nextX][nextY] == 'T')
            continue;

        dist[nextX][nextY] = dist[x][y] + 1;
        solve(nextX, nextY);
        dist[nextX][nextY] = -1;
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;
    for (int i = 0; i < R; ++i)
        cin >> board[i];
    fill(&dist[0][0], &dist[0][0] + 25, -1);
    dist[R - 1][0] = 1;

    solve(R - 1, 0);

    cout << cnt;
}