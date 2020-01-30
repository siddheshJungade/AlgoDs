#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    string s1;
    cin>>s1;

    s.append(s1);
    cout<<s<<endl;

    string s2 = s.substr(0,5);
    cout<<s2<<endl;
    cout<<s2.erase(2);
    return 0;
}

