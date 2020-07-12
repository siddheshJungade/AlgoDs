#include<iostream>
#include <math.h>
using namespace std;
int cutMax(int n, int a,int b ,int c){
    
    int res = max(cutMax(n-a,a,b,c),cutMax(n-b,a,b,c),cutMax(n-c,a,b,c));

    if(res == -1)
        return -1;

    return res +1;
    


}

int main(int argc, char const *argv[])
{
    int n ,a,b,c ;cin >> n >> a >> b >> c ;
    cout << cutMax(n,a , b , c) << endl;
    return 0;
}
