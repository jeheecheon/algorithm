#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    string n1;
    string n2;

    cin >> n1 >> n2;

    for (int i = 0; i < n1.length(); i++) {
        if (n1[i] == '5') {
            n1[i] = '6';
        }
    }
    for (int i = 0; i < n2.length(); i++) {
        if (n2[i] == '5') {
            n2[i] ='6';
        }
    }
    int a = stoi(n1);
    int b = stoi(n2);

    

    for (int i = 0; i < n1.length(); i++) {
        if (n1[i] == '6') {
            n1[i] = '5';
        }
    }
    for (int i = 0; i < n2.length(); i++) {
        if (n2[i] == '6') {
            n2[i] = '5';
        }
    }
    int c = stoi(n1);
    int d = stoi(n2);

    cout << c + d << " ";
    cout << a + b << " ";
}