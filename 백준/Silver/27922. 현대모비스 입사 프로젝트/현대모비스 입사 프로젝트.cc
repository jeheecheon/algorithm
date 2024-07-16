#include <algorithm>
#include <iostream>

using namespace std;
int N, K;
int arr1[100000], arr2[100000], arr3[100000];

bool mycomp(int f, int s)
{
    return f > s;
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        arr1[i] = a + b;
        arr2[i] = a + c;
        arr3[i] = b + c;
    }

    sort(arr1, arr1 + N, mycomp);
    sort(arr2, arr2 + N, mycomp);
    sort(arr3, arr3 + N, mycomp);

    int sum[3] = { 0 };
    for (int i = 0; i < K; ++i) {
        sum[0] += arr1[i];
        sum[1] += arr2[i];
        sum[2] += arr3[i];
    }

    cout << *max_element(sum, sum + 3);
}