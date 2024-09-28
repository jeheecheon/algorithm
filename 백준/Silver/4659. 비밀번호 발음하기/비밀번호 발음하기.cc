// baekjoon 4659

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using point = pair<int, int>;

vector<pair<int, int>> dirs = {
    { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }
};

bool is_vowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    string str;
    while (cin >> str) {
        if (str == "end")
            break;

        bool result = true;
        bool hasVowel = false;
        for (int i = 0; i < str.length(); ++i) {
            if (!hasVowel)
                hasVowel = is_vowel(str[i]);

            if (i + 2 < str.length()) {
                bool fir = is_vowel(str[i]);
                bool sec = is_vowel(str[i + 1]);
                bool thr = is_vowel(str[i + 2]);

                if ((fir && sec && thr) || (!fir && !sec && !thr)) {
                    result = false;
                    break;
                }
            }

            if (i > 0 && str[i - 1] == str[i] && str[i] != 'e' && str[i] != 'o') {
                result = false;
                break;
            }
        }
        cout << '<' << str << '>';

        if (result && hasVowel) {
            cout << " is acceptable." << endl;
        } else {
            cout << " is not acceptable." << endl;
        }
    }
}