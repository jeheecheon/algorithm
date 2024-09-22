// baekjoon 8933

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

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int A = 0, G = 0, T = 0, C = 0;
        string DNA;
        int k;
        cin >> k >> DNA;
        map<tuple<int, int, int, int>, int> M;

        for (int i = 0; i < k; ++i) {
            if (DNA[i] == 'A')
                ++A;
            else if (DNA[i] == 'G')
                ++G;
            else if (DNA[i] == 'T')
                ++T;
            else
                ++C;
        }

        ++M[{A, G, T, C}];

        int st = 0, end = k - 1;
        while (end + 1 < DNA.length()) {
            if (DNA[st] == 'A')
                --A;
            else if (DNA[st] == 'G')
                --G;
            else if (DNA[st] == 'T')
                --T;
            else
                --C;

            ++st;
            ++end;

            if (DNA[end] == 'A')
                ++A;
            else if (DNA[end] == 'G')
                ++G;
            else if (DNA[end] == 'T')
                ++T;
            else
                ++C;

            ++M[{A, G, T, C}];
        }

        int maxi = 0;
        for (auto n : M) 
            maxi = max(maxi, n.second);
        cout << maxi << '\n';
    }
    return 0;
}