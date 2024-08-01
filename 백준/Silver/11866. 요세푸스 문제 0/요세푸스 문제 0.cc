#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    queue<int> Q;
    for (int i = 1; i <= n; ++i)
        Q.push(i);

    vector<int> ans;

    int cur = 0;

    while (!Q.empty()) {
        int num = Q.front();
        Q.pop();

        ++cur;
        if (cur != k) {
            Q.push(num);
        } else {
            cur = 0;
            ans.push_back(num);
        }
    }

    cout << "<";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << ">";
}