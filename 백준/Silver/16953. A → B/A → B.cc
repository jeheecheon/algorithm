#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int A, B;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> A >> B;
    queue<pair<long long, int>> Q; // val, cnt
    Q.push({ A, 0 });
    int ans = 0x7fffffff;
    while (!Q.empty()) {
        auto [curVal, curCnt] = Q.front();
        Q.pop();

        if (curVal == B) {
            ans = min(ans, curCnt);
            continue;
        }

        vector<long long> nextVals = {
            curVal * 10 + 1,
            curVal * 2
        };
        for (long long nextVal : nextVals) {
            if (nextVal > B)
                continue;
            Q.push({nextVal, curCnt + 1});
        }
    }

    cout << (ans == 0x7fffffff ? -1 : ans + 1);
}
