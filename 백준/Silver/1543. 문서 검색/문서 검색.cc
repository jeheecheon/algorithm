#include <iostream>

using namespace std;

int main(void) {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int cur = 0;
    int ans = 0;

    for (int i = 0; i + str2.length() <= str1.length(); ) {
        bool found = true;
        for (int j = 0; j < str2.length(); ++j) {
            if (str1[i + j] != str2[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            ++ans;
            i += str2.length();
        } else {
            ++i;
        }
    }

    cout << ans;
}