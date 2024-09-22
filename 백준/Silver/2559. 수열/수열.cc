// baekjoon 2559

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

int main(void) {
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
        cin >> arr[i];
    
    int sum = 0;
    for (int i = 0; i < K; ++i)
        sum += arr[i];

    int ans = sum;
    int st = 0, end = K - 1;
    while (end + 1 < arr.size()) {
        sum = sum - arr[st++] + arr[++end];
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}