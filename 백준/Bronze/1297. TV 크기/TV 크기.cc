// baekjoon 1297

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int d, w, h;
    std::cin >> d >> w >> h;

    double k = d / sqrt(w * w + h * h);

    int actual_w = int(w * k);
    int actual_h = int(h * k);

    std::cout << actual_w << " " << actual_h << std::endl;
}