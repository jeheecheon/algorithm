// baekjoon 21318

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    int N, T;
    cin >> N;
    vector<int> arr(N + 1, 0), pre(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if (arr[i] < arr[i - 1])
            pre[i] = 1;
        pre[i] += pre[i - 1];
    }        

    cin >> T;
    int a, b;
    while (T--) {
        cin >> a >> b;
        cout << pre[b] - pre[a] << endl;
    }
}
