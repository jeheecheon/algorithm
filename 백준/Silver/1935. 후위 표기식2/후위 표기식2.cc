// baekjoon 1935

#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int N, vals[26];
    string str;
    cin >> N >> str;
    
    for (int i = 0; i < N; i++)
        cin >> vals[i];
    
    stack<double> s;
    for (char ch : str) {
        if (ch >= 'A' && ch <= 'Z') {
            s.push(vals[ch - 'A']);
        } else {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    cout << fixed << setprecision(2) << s.top();
}