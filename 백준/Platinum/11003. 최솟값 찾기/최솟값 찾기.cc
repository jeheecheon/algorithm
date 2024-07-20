#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, l;
    int tmp;
    
    cin >> n >> l;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;

        while (!dq.empty() && dq.back().second >= tmp) {
            dq.pop_back();
        }

        dq.push_back({i, tmp});

        if (dq.front().first <= i - l) {
            dq.pop_front();
        }

        cout << dq.front().second << ' ';
    }    
}