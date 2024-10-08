#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    queue<int> q;
    int n;
    cin >> n;
    while (n--) {
        int num;
        string str;
        cin >> str;

        if (str == "push") {
            cin >> num;
            q.push(num);
        } else if (str == "pop") {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (str == "size")
            cout << q.size() << '\n';
        else if (str == "empty")
            cout << q.empty() << '\n';
        else if (str == "front") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.front() << '\n';

        } else if (str == "back") {
            if (q.empty())
                cout << -1 << '\n';
            else
                cout << q.back() << '\n';
        }
    }
}