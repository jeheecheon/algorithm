#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string serials[n];
    for (string& s : serials)
        cin >> s;

    sort(&serials[0], &serials[n], [](string first, string second) {
        if (first.length() == second.length()) {
            int firVal = 0, secVal = 0;
            for (int i = 0; i < first.length(); ++i) {
                if (first[i] >= '0' && first[i] <= '9')
                    firVal += first[i] - '0';
                if (second[i] >= '0' && second[i] <= '9')
                    secVal += second[i] - '0';
            }
            if (firVal == secVal) {
                return strcmp(first.c_str(), second.c_str()) <= 0 ? true : false;
            } else {
                return firVal <= secVal;
            }
        } else {
            return first.length() < second.length();
        }
    });

    for (auto s : serials)
        cout << s << '\n';
}