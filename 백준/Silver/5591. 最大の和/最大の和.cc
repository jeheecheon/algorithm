// baekjoon 5591

#include <iostream>
#include <cmath>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using point = pair<int, int>;

#define X first
#define Y second

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    ll sum = 0;
    for (int i = 0; i < k; ++i)
        sum += arr[i];

    int st = 0, end = k - 1;

    ll maxi = sum;
    while (end + 1 < n) {
        sum -= arr[st++];
        sum += arr[++end];

        maxi = max(maxi, sum);
    }

    cout << maxi;
}