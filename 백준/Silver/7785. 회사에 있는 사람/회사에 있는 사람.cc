// baekjoon 7785

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<string, string> M;
    while (N--) {
        string str1, str2;
        cin >> str1 >> str2;
        M[str1] = str2;
    }

    vector<string> ans;
    for (auto [name, status] : M) {
        if (status == "enter")
            ans.push_back(name);
    }

    sort(ans.begin(), ans.end(), greater<string>());
    for (auto e : ans)
        cout << e << endl;
}