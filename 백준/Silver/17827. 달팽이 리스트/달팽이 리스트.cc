#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M, V;

pair<int, int> dirs[4] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> M >> V;

    vector<int> list(N + 1);
    for (int i = 0; i < N; ++i)
        cin >> list[i];

    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;

        int asd = 0;
        if (k > N) {
            k -= N;
            k %= (N - V + 1);
            asd += k + V - 1;
        } else {
            asd += k;
        }
        if (asd == N)
            cout << list[V - 1] << '\n';
        else
            cout << list[asd] << '\n';
    }
}
