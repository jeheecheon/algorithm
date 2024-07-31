#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    cin.tie(0)->tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin >> N;

    unordered_map<int, int> cards;
    while (N--) {
        int tmp;
        cin >> tmp;
        ++cards[tmp];
    }

    cin >> M;
    while (M--) {
        int tmp;
        cin >> tmp;
        cout << cards[tmp] << ' ';
    }
}