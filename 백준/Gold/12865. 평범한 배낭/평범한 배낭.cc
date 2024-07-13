#include <iostream>

using namespace std;

pair<int, int> items[102];
int dp[100002];

int N, K;

int main(void)
{
    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        cin >> items[i].first >> items[i].second;

    for (int i = 0; i < N; ++i) {
        for (int j = K; j >= 0; --j) {
            if (j >= items[i].first) {
                dp[j] = max(
                    dp[j],
                    dp[j - items[i].first] + items[i].second);
            }
        }
    }

    cout << dp[K];
}