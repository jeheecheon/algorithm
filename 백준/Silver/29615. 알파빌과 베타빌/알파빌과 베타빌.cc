#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int N, M;
unordered_set<int> s;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    int tmp;
    for (int i = 1; i <= N; ++i) {
        cin >> tmp;

        if (i <= M)
            s.insert(tmp);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        if (s.find(tmp) == s.end())
            ++ans;
    }
    
    cout << ans;
}