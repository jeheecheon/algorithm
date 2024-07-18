#include <iostream>
#include <unordered_map>

using namespace std;

int T, N;

int main(void)
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        unordered_map<string, int> mymap;
        while (N--)
        {
            string category;
            cin >> category >> category;
            mymap[category]++;
        }

        int result = 1;
        for (auto [k, v] : mymap)
            result *= (v + 1);
            
        result -= 1;

        cout << result << '\n';
    }
    return 0;
}
