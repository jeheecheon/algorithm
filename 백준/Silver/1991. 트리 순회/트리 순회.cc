#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<char, char> nodes[26];

void pre(int i)
{
    cout << (char)(i + 'A');
    if (nodes[i].first != '.')
        pre(nodes[i].first - 'A');
    if (nodes[i].second != '.')
        pre(nodes[i].second - 'A');
}

void mid(int i)
{
    if (nodes[i].first != '.')
        mid(nodes[i].first - 'A');
    cout << (char)(i + 'A');
    if (nodes[i].second != '.')
        mid(nodes[i].second - 'A');
}

void pro(int i)
{
    if (nodes[i].first != '.')
        pro(nodes[i].first - 'A');
    if (nodes[i].second != '.')
        pro(nodes[i].second - 'A');
    cout << (char)(i + 'A');
}

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 26; ++i)
        nodes[i] = { '.', '.' };

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char tmp;
        cin >> tmp >> nodes[tmp - 'A'].first >> nodes[tmp - 'A'].second;
    }

    pre(0);
    cout << '\n';
    mid(0);
    cout << '\n';
    pro(0);
}
