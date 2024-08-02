#include <iostream>

using namespace std;

int solve(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    return solve(n - 1, k - 1) + solve(n - 1, k);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
}