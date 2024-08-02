#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string str;
    cin >> N >> str;

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += (str[i] - 'a' + 1) * pow(31, i);
        sum %= 1234567891;
    }
    cout << sum;
    return 0;
}
