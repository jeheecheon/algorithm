// baekjoon 1485

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

#define X first
#define Y second

using namespace std;
using point = pair<int, int>;

double distance(const point& A, const point& B)
{
    return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        point A, B, C, D;
        cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y >> D.X >> D.Y;

        unordered_set<double> s;
        s.insert(distance(A, B));
        s.insert(distance(A, C));
        s.insert(distance(A, D));
        s.insert(distance(B, C));
        s.insert(distance(B, D));
        s.insert(distance(C, D));


        cout << (s.size() == 2) << '\n';
    }
}