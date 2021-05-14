#include<iostream>
#include<string>
using namespace std;

bool isPalandrom(string s,int n){
    if(n <= 1)
        return true;
    if(s[0] != s[n])
        return false;
        
    return isPalandrom(s.substr(1),n-1);
};
int main(int argc, char const *argv[])
{
    string s ; cin >> s;
    cout<<isPalandrom(s,s.size()-1);
    return 0;
}
