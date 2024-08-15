// baekjoon 1010

#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;

        int a = 1;
        for (int i = 1; i <= n; ++i) {
            a *= m - i + 1;
            a /= i;
        }
        cout << a << '\n';
    }
}