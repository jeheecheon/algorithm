// baekjoon 1531

#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    int img[101][101] = { 0 };

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                ++img[x][y];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (img[i][j] > M)
                ++ans;
        }
    }
    cout << ans;
}
