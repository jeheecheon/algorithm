#include <iostream>
#include <vector>

using namespace std;

pair<int, int> items[100];

int N, M;
int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> items[i].first;

    for (int i = 0; i < N; ++i)
        cin >> items[i].second;

    vector<int> dp(10001, 0);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 10000; j >= items[i].second; --j)
        {
            dp[j] = max(
                dp[j],
                dp[j - items[i].second] + items[i].first);
        }
    }

    int minCost = 0;
    for (int j = 0; j <= 10000; ++j)
    {
        if (dp[j] >= M)
        {
            minCost = j;
            break;
        }
    }
    cout << minCost;
}