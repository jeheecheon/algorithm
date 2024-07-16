#include <algorithm>
#include <iostream>

using namespace std;

int N;
pair<int, int> times[100001];

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> times[i].first >> times[i].second;
    }

    sort(times, times + N, [](pair<int, int> f, pair<int, int> s) {
        if (f.second == s.second) {
            return f.first < s.first;
        } else {
            return f.second < s.second;
        }
    });

    int cnt = 0;
    int last_end_time = 0;

    for (int i = 0; i < N; ++i) {
        if (times[i].first >= last_end_time) {
            last_end_time = times[i].second;
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
