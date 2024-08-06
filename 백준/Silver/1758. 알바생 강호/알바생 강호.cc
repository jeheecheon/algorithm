// baekjoon 1758

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    while (N--)
        cin >> arr[N];

    sort(arr.begin(), arr.end(), greater<>());

    long long sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] - i > 0)
            sum += arr[i] - i;
    }

    cout << sum;
}