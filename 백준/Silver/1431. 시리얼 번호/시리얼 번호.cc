// baekjoon 1431

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isAlphabet(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

int main()
{
    int n;
    cin >> n;
    vector<string> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end(), [](string a, string b) {
        if (a.length() != b.length()) {
            return a.length() <= b.length();
        }

        int l = a.length();

        int ASum = 0, BSum = 0;
        for (int i = 0; i < l; ++i) {
            if (!isAlphabet(a[i])) {
                ASum += a[i] - '0';
            }

            if (!isAlphabet(b[i])) {
                BSum += b[i] - '0';
            }
        }

        if (ASum != BSum) {
            return ASum <= BSum;
        }

        return a <= b;
    });

    for (string& s : p)
        cout << s << '\n';
}