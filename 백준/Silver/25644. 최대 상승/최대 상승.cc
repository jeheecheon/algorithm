#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int maxi = 0;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        maxi = max(maxi, arr[i]);
        ans = max(ans, maxi - arr[i]);
    }

    cout << ans;
}