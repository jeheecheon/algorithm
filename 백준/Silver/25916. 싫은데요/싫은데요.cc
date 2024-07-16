#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

long long N, M;
long long arr[500001];
int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    long long st = 0, en = 0;
    long long sum = 0;
    long long maxi = 0;

    while (en < N) {
        sum += arr[en++];

        if (sum <= M)
            maxi = max(maxi, sum);

        while (sum > M) {
            sum -= arr[st++];
            if (sum <= M)
                maxi = max(maxi, sum);
        }
    }

    cout << maxi;
}