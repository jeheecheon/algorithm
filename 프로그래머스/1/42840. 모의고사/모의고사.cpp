#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p[4] = { 0 };
    
    vector<int> sheet1 = {1, 2, 3, 4, 5};
    vector<int> sheet2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> sheet3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int i1 = 0, i2 = 0, i3 = 0;
    
    for (auto a : answers) {
        p[1] += sheet1[i1++] == a;
        p[2] += sheet2[i2++] == a;
        p[3] += sheet3[i3++] == a;
        
        i1 = i1 % sheet1.size();
        i2 = i2 % sheet2.size();
        i3 = i3 % sheet3.size();
    }
    if (p[1] > p[2]) {
        if (p[1] > p[3]) {
            answer.push_back(1);
        } else {
            answer.push_back(3);
        }
    } else {
        if (p[2] > p[3]) {
            answer.push_back(2);            
        } else {
            answer.push_back(3);
        }
    }
    for (int i = 1; i <= 3; ++i) {
        if (i == answer[0])
            continue;
        if (p[i] == p[answer[0]])
            answer.push_back(i);   
    }
    sort(answer.begin(), answer.end());
    return answer;
}