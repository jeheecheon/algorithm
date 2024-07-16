#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    stringstream ss(str);

    vector<string> subs;
    while (getline(ss, str, '-'))
        subs.push_back(str);

    int sum = 0;
    ss.clear();
    ss.str(subs[0]);
    while (getline(ss, str, '+'))
        sum += stoi(str);

    for (int i = 1; i < subs.size(); ++i) {
        ss.clear();
        ss.str(subs[i]);
        while (getline(ss, str, '+'))
            sum -= stoi(str);
    }

    cout << sum;
}
