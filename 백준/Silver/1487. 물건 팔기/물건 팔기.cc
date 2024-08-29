// baekjoon 1487

#include <algorithm>
#include <iostream>
#include <vector>

#define X first
#define Y second

using namespace std;
using point = pair<int, int>;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    vector<point> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i].X >> v[i].Y;

    point ans = { 0, 0 };
    sort(v.begin(), v.end(), [](const point& a, const point& b) {
        return a.X < b.X;
    });

    for (int i = 0; i < N; ++i) {
        int sum = 0;

        for (int j = i; j < N; ++j) {
            int input = v[i].X - v[j].Y;
            if (input > 0)
                sum += input;
        }

        if (sum > ans.Y)
            ans = { i, sum };
    }

    cout << (ans.Y ? v[ans.X].X : 0);
}