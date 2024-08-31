// baekjoon 2371

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<ll>> files(N);

    ll largest_filesize = 0;
    for (int i = 0; i < N; ++i) {
        while (true) {
            int tmp;
            cin >> tmp;
            if (tmp == -1)
                break;
            files[i].push_back(tmp);
        }
        largest_filesize = (largest_filesize < files[i].size()) ? files[i].size() : largest_filesize;
    }

    for (int i = 0; i < largest_filesize; ++i) {
        unordered_set<ll> s;

        int cnt = N;
        for (int j = 0; j < N; ++j) {
            if (i < files[j].size()) {
                s.insert(files[j][i]);
            } else {
                --cnt;
            }
        }

        if (s.size() == cnt) {
            cout << i + 1;
            break;
        }
    }
}