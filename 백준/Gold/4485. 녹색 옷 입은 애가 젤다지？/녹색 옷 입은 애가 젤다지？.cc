#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C;

pair<int, int> dirs[4] = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int arr[125][125];
int N;

void solve(int i)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;

    PQ.push({ arr[0][0], 0, 0 });
    vector<vector<int>> dist(N, vector<int>(N, 0x7fffffff));
    dist[0][0] = arr[0][0];
    while (!PQ.empty()) {
        auto [val, x, y] = PQ.top();
        PQ.pop();

        if (x == N - 1 && y == N - 1) {
            cout << "Problem " << i << ": " << val << '\n';
            return;
        }

        if (val > dist[x][y])
            continue;

        for (auto [dirX, dirY] : dirs) {
            auto [destX, destY] = pair { x + dirX, y + dirY };

            if (destX < 0 || destY < 0 || destX >= N || destY >= N)
                continue;

            int newDist = val + arr[destX][destY];
            if (newDist < dist[destX][destY]) {
                dist[destX][destY] = newDist;
                PQ.push({ newDist, destX, destY });
            }
        }
    }
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int i = 1;
    while (true) {
        cin >> N;
        if (N == 0)
            return 0;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> arr[i][j];

        solve(i++);
    }
}
