// baekjoon 2167

#include <bits/stdc++.h>

using namespace std;
using point = pair<int, int>;
using ll = long long;

#define X first
#define Y second

point dirs[4] {
    { 0, 1 },
    { 1, 0 },
    { -1, 0 },
    { 0, -1 }
};

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> prefixSum(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> prefixSum[i][j];
            prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    int K;
    cin >> K;

    while (K--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << prefixSum[x][y] - prefixSum[i - 1][y] - prefixSum[x][j - 1] + prefixSum[i - 1][j - 1] << '\n';
    }

    return 0;
}