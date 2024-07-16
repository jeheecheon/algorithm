#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int N, K;
int cof[101];
int dp[100001];

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> cof[i];

    fill(dp, dp +100001, 100001);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = K; j >= cof[i]; --j) {
            dp[j] = min(
                dp[j],
                dp[j - cof[i]] + 1
            );
        }
    }

    cout << (dp[K] == 100001 ? -1 : dp[K]);
}
