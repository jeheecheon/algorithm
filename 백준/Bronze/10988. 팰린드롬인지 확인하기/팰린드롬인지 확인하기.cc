// baekjoon 10988

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    string word;
    cin >> word;
    
    int a = 0, b = word.length() - 1;
    bool same = true;
    for (; a < word.length(); ++a, --b) {
        if (word[a] != word[b]) {
            same = false;
            break;
        }
    }

    cout << same;
}