#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;
    int limit = stoi(str);
    for (int i = 1; i <= limit; ++i) {
        int sum = i;

        int tmp = i;
        while (tmp != 0) {
            sum += tmp % 10;
            tmp /= 10;
        }

        if (sum == limit) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}