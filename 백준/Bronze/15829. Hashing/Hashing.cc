#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string str;
    cin >> N >> str;

    long long sum = 0;
    long long pow_mult = 1;
    for (int i = 0; i < N; ++i) {
        sum = (sum + (str[i] - 'a' + 1) * pow_mult) % 1234567891;
        pow_mult = (pow_mult * 31) % 1234567891;
    }

    cout << sum;
    return 0;
}
