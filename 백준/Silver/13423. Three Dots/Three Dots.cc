#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;
int T, N;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> N;
        int points[N] = { 0 };
        for (int i = 0; i < N; ++i)
            cin >> points[i];

        sort(points, points + N);

        int ans = 0;
        for (int i = 0; i < N - 2; ++i) {
            for (int j = i + 1; j < N - 1; ++j) {
                int target = points[j] - (points[i] - points[j]);
                if (binary_search(points, points + N, target))
                    ++ans;
            }
        }
        cout << ans << '\n';
    }
}