// baekjoon 31848

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using point = pair<int, int>;
using ll = long long;

vector<point> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int N;
    int holes[100002], doto[100002];

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> holes[i];
        holes[i] += i - 1;
    }

    int size = 1;
    for (int i = 1; i <= 100000; ++i) {
        while (size <= holes[i] && size <= 100000) {
            doto[size++] = i;
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int tmp;
        cin >> tmp;
        cout << doto[tmp] << ' ';
    }
}