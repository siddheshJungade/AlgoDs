#include <iostream>
using namespace std;
void b(int n);

void a(int n){
    if(n > 0){
        cout << n << " ";
        b(n-1);
    }
}
void b(int n){
    if(n>0){
        cout << n << " ";
        a(n/2);
    }
}

int main(int argc, char const *argv[])
{
    a(20);
    return 0;
}
