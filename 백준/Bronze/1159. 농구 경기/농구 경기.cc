// baekjoon 1159

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> arr(26, 0);
    while (n--) {
        string name;
        cin >> name;
        ++arr[name[0] - 'a'];
    }

    bool asnwered = false;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] >= 5) {
            asnwered = true;
            cout << (char)(i + 'a');
        }
    }

    if (!asnwered)
        cout << "PREDAJA";
}