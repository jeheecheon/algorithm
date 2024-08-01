#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    int arr[n];

    // input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 첫 번째 구간 계산
    int ans;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    ans = sum;

    // 구간별 비교
    int st = 1;
    int ed = k % n;

    while (st < n) {
        sum -= arr[st - 1];
        sum += arr[ed];

        ans = max(ans, sum);

        st++;
        ed++;
        if (ed >= n)
            ed = 0;
    }

    cout << ans;
}