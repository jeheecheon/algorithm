#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> courses(N);
    for (int i = 0; i < N; ++i)
        cin >> courses[i].first >> courses[i].second;
    vector<int> dp(T + 1);
    for (int i = 0; i < N; ++i)
        for (int j = T; j >= courses[i].first; --j)
            dp[j] = max(
                dp[j],
                dp[j - courses[i].first] + courses[i].second);

    cout << dp[T];
}