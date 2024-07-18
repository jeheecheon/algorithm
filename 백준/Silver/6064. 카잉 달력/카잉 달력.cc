#include <iostream>

using namespace std;

int T, M, N, X, Y;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--)
    {
        cin >> M >> N >> X >> Y;

        int l = M * N;
        int ans = -1;
        for (int k = X - 1; k < l; k += M) {
            if (k % N + 1 == Y) {
                ans = k + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}
