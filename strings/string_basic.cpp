#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    string e_stk;
    cin>>e_stk;

    s.append(e_stk);
    cout<<s<<endl;

    string d_stk = s.substr(0,5);
    cout<<d_stk<<endl;
    cout<<d_stk.erase(2);
    return 0;
}

