#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int X[1000002];

bool solve(long long mid)
{
    int kTemp = K;
    for (int i = 0; i < N; ++i) {
        if (X[i] >= mid)
            continue;

        long long dif = mid - X[i];
        if (dif > kTemp)
            return false;

        kTemp -= dif;
    }
    return kTemp >= 0;
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> X[i];

    long long end = *max_element(X, X + N) + K, st = 1;
    long long ans = 0;
    while (st <= end) {
        long long mid = (st + end) / 2;

        if (solve(mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans;
}