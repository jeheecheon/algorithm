#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector<pair<int, int>> positions(N);
    for (int i = 0; i < N; ++i)
        cin >> positions[i].first >> positions[i].second;

    sort(positions.begin(), positions.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    for (auto kv : positions)
        cout << kv.first << ' ' << kv.second << '\n';

    return 0;
}
