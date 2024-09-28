// baekjoon 1940

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (arr[i] + arr[j] == M)
                ++cnt;
        }
    }

    cout << cnt;
}