#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int coins[18];
    for (int i = 1; i <= 17; ++i)
        coins[i] = i * i;

    while (1) {
        int N;
        cin >> N;
        if (!N)
            break;

        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= 17; ++i) {
            for (int j = coins[i]; j <= N; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[N] << '\n';
    }
}