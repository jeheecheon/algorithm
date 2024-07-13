#include <iostream>

using namespace std;
using int64 = long long;

int N, M;
int logs[1000002];

bool solve(int64 mid)
{
    int64 ans = 0;
    for (int i = 0; i < N; ++i) {
        if (logs[i] <= mid)
            continue;

        ans += logs[i] - mid;
        if (ans >= M)
            return true;
    }
    return false;
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> logs[i];

    int64 st = 0, en = 1e9;
    int ans = 0;

    while (st <= en) {
        int64 mid = (st + en) / 2;

        if (solve(mid)) {
            st = mid + 1;
            ans = mid;
        }
        else {
            en = mid - 1;
        }
    }

    cout << en;
}
