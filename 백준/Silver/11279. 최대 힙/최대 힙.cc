#include <iostream>
#include <set>

using namespace std;

int N;
multiset<long long> myset;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);

    cin >> N;
    while (N--) {
        long long tmp;
        cin >> tmp;
        if (tmp == 0) {
            auto it = myset.end();
            if (it != myset.begin()) {
                cout << *(--it) << '\n';
                myset.erase(it);
            } else {
                cout << 0 << '\n';
            }
        } else {
            myset.insert(tmp);
        }
    }
}