#include <cmath>
#include <iostream>

using namespace std;

bool canConvertToInt(const string& str)
{
    try {
        size_t pos;
        int num = stoi(str, &pos);
        // Check if there are any non-digit characters left after the conversion
        return pos == str.size();
    } catch (...) {
        return false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string str[3];
    cin >> str[0] >> str[1] >> str[2];

    for (int i = 0; i < 3; ++i) {
        bool isConvertable = canConvertToInt(str[i]);
        if (!isConvertable)
            continue;

        int num = stoi(str[i]) + 3 - i;
        if (num % 3 == 0 && num % 5 == 0) {
            cout << "FizzBuzz";
        }
        else if (num % 3 == 0) {
            cout << "Fizz";
        } else if (num % 5 == 0) {
            cout << "Buzz";
        } else {
            cout << num;
        }
        return 0;
    }
}
