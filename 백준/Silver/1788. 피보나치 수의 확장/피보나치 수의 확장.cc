// baekjoon 1788

#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<int, ll> m;
    int n;
    cin >> n;

    m[0] = 0;
    m[1] = 1;

    if (n < 0) {
        for (int i = -1; i >= n; --i) {
            m[i] = m[i + 2] - m[i + 1];
            m[i] %= 1000000000;
        }
    } else {
        for (int i = 2; i <= n; ++i) {
            m[i] = m[i - 1] + m[i - 2];
            m[i] %= 1000000000;
        }
    }

    if (m[n] == 0) {
        cout << 0 << '\n';
    } else {
        cout << (m[n] > 0 ? 1 : -1) << '\n';
    }

    cout << abs(m[n]);
}