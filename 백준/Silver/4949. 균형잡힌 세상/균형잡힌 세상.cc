#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOpeningOne(char ch)
{
        return (ch == '[' || ch == '{' || ch == '(');
}

bool isClosingOne(char ch)
{
        return (ch == ']' || ch == '}' || ch == ')');
}

bool arePair(char ch1, char ch2)
{
        return (ch1 == '[' && ch2 == ']') || (ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}');
}

int main(void)
{
        cin.tie(0);
        ios::sync_with_stdio(0);

        stack<char> st;
        string input;

        while (true)
        {
                getline(cin, input);

                if (input.length() == 1 && input[0] == '.')
                        return false;

                bool answer = true;
                stack<char> st;
                for (char ch : input)
                {
                        if (isOpeningOne(ch))
                        {
                                st.push(ch);
                        }
                        else if (isClosingOne(ch))
                        {
                                if (!st.empty())
                                {
                                        auto top = st.top();
                                        st.pop();

                                        if (!arePair(top, ch))
                                        {
                                                answer = false;
                                        }
                                }
                                else {
                                        answer = false;
                                }
                        }
                }
                if (!st.empty())
                        answer = false;
                cout << (answer ? "yes" : "no") << '\n';
        }
}