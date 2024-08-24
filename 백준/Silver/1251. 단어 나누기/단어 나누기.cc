// baekjoon 1251

#include <algorithm>
#include <iostream>

using namespace std;

void reverse(string& str, int st, int end)
{
    while (st < end) {
        swap(str[st], str[end]);
        ++st, --end;
    }
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    string result = "~";
    for (int i = 1; i < str.length() - 1; ++i) {
        for (int j = i + 1; j < str.length(); ++j) {
            string temp = str;

            reverse(temp, 0, i - 1);
            reverse(temp, i, j - 1);
            reverse(temp, j, temp.length() - 1);

            result = (temp < result) ? temp : result;
        }
    }

    cout << result;
}
