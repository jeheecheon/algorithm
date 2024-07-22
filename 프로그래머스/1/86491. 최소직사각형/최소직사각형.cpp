#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int s1 = 0, s2 = 0;
    for (auto card : sizes) {
        sort(&card[0], &card[2]);
        s1 = max(s1, card[0]);
        s2 = max(s2, card[1]);
    }
    
    return s1 * s2;
}