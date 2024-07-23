#include <cmath>
#include <iostream>

using namespace std;

int N;
int ans = 0x7fffffff;
pair<int, int> mat[10];

void solve(int cur, int sin, int ssn)
{
    ans = min(ans, abs(sin - ssn));

    for (int i = cur + 1; i < N; ++i) {
        solve(i, sin * mat[i].first, ssn + mat[i].second);
    }
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> mat[i].first >> mat[i].second;

    for (int i = 0; i < N; ++i)
        solve(i, mat[i].first, mat[i].second);

    cout << ans;
}