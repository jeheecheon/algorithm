#include <iostream>

using namespace std;

int N, S;
int arr[100000];

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int st = 0, end = 0;
    int curSum = 0;
    int cnt = 0;

    while (end < N)
    {
        curSum += arr[end++];

        while (curSum >= S)
        {
            if (curSum == S)
                ++cnt;
            curSum -= arr[st++];
        }
    }

    cout << cnt;
}