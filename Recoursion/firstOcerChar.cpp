#include<iostream> 
#include<string>
using namespace std;

int firstOcer(char *c , char f){
    static int i = 0 ;
    if(*c =='\0')
        return -1;
    if(*c == f )
        return i ;
    
    i++;
    firstOcer(c+1 , f);
}


int main(int argc, char const *argv[])
{
    string s ; cin >> s ;

    char c ; cin >> c ;

    cout << firstOcer(&s[0],c);
    return 0;
}

