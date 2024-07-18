#include <iostream>
#include <map>

using namespace std;

int N;
map<long long, pair<int, int>> mymap;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> N;
    while (N--) {
        long long tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (mymap.empty()) {
                cout << 0 << '\n';
            } else {
                auto it = mymap.begin();
                auto& [k, v] = *it;
                auto& [m, p] = v;

                if (m) {
                    cout << -k << '\n';
                    --m;
                } else {
                    cout << k << '\n';
                    --p;
                }

                if (!m && !p)
                    mymap.erase(it);
            }
        } else {
            auto& [minus, plus] = mymap[abs(tmp)];
            tmp > 0 ? ++plus : ++minus;
        }
    }
}