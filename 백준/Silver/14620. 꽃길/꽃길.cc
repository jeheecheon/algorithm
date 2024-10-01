// baekjoon 14620

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<point> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 0 }
};

int n;
int board[10][10];
bool vis[10][10];
int sum;
int ans = 0x7fffffff;

void solve(int k)
{
    if (k == 3) {
        ans = min(ans, sum);
        return;
    }

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            bool pos = true;
            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = point { i + dx, j + dy };
                if (vis[nx][ny]) {
                    pos = false;
                    break;
                }
            }
            if (!pos)
                continue;

            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = point { i + dx, j + dy };
                vis[nx][ny] = true;
                sum += board[nx][ny];
            }

            solve(k + 1);

            for (auto [dx, dy] : dirs) {
                auto [nx, ny] = point { i + dx, j + dy };
                vis[nx][ny] = false;
                sum -= board[nx][ny];
            }
        }
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    solve(0);
    cout << ans;
}