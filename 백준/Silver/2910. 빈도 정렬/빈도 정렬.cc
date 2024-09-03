// baekjoon 2910

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;

    vector<int> arr(N);
    unordered_map<int, int> m;
    unordered_map<int, int> fre;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        ++m[arr[i]];
        if (!fre[arr[i]]) {
            fre[arr[i]] = i + 1;
        }
    }

    sort(arr.begin(), arr.end(), [&m, &fre](int a, int b) {
        if(m[a] > m[b]) {
            return true;
        } else if (m[a] == m[b]) {
            return fre[a] < fre[b];
        } else {
            return false;
        };
    });

    for (int& a : arr)
        cout << a << ' ';
}