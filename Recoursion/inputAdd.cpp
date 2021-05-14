#include<iostream>
using namespace std;

int inputAdd(int n,int res){
    if(n <= 0)
        return res;
    
    int num ; cin >> num ;
    inputAdd(n-1,res+num);
}


int main(int argc, char const *argv[])
{
    int n ; cin >> n ; 
    cout << inputAdd(n,0);
    return 0;
}
