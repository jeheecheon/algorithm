#include <algorithm>
#include <iostream>

using namespace std;
int N, K;
int arr[100001];
int acc[100001];
int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    for (int i = 0; i < K; ++i) {
        acc[0] += arr[i];
    }

    int st = 1, en = K;
    for (int i = 1; i < N; ++i) {
        acc[i] = acc[i - 1] - arr[st - 1] + arr[en];
        ++st, ++en;
        if (en >= N) {
            en = en % N;
        }
    }

    cout << *max_element(&acc[0], &acc[N]);
}