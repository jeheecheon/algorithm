#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int f[11] = { 0 };

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int st = 0, en = 0;

    int cnt = 1;
    f[arr[0]] = 1;
    int ans = 1;
    while (++en < n) {
        if (f[arr[en]] == 0) 
            ++cnt;
        ++f[arr[en]];

        while (cnt > 2) {
            if (--f[arr[st++]] == 0)
                --cnt;
        }

        ans = max(ans, en - st + 1);
    }

    cout << ans;
}