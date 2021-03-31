#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalance(string exp)
{
    stack<char> st;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' or exp[i] == '{' or exp[i] == '[')
            st.push(exp[i]);
        else if ((exp[i] == ')' and st.top() == '(') or (exp[i] == '}' and st.top() == '{') or (exp[i] == ']' and st.top() == '[') )
        {
            if (st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty() ? true : false;
}
 
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << isBalance(s);
    return 0;
}
