#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);

    int sum = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
        ++m[v[i]];
    }

    sort(v.begin(), v.end());

    vector<pair<int, int>> freq;
    for (auto& kv : m) {
        auto [num, fre] = kv;

        freq.push_back({ num, fre });
    }

    sort(freq.begin(), freq.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    cout
        << (int)round(sum / (double)n) << '\n';
    cout << v[n / 2] << '\n';

    int a = freq[0].first;

    if (freq.size() >= 1 && freq[1].second == freq[0].second) 
        a = freq[1].first;
    cout << a << '\n';
    cout << v[n - 1] - v[0];
}