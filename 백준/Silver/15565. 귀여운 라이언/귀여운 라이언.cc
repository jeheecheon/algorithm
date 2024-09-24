// baekjoon 15565

#include <bits/stdc++.h>

using namespace std;
using point = pair<int, int>;
using ll = long long;

#define X first
#define Y second

point dirs[4] {
    { 0, 1 },
    { 1, 0 },
    { -1, 0 },
    { 0, -1 }
};

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int cnt = 0;
    int st = 0;
    int ans = 0x7fffffff;

    for (int end = 0; end < n; ++end) {
        if (arr[end] == 1)
            ++cnt;

        while (cnt == k) {
            ans = min(ans, end - st + 1);

            if (arr[st++] == 1) 
                --cnt;
        }
    }

    if (ans == 0x7fffffff)
        cout << -1;
    else
        cout << ans;

    return 0;
}