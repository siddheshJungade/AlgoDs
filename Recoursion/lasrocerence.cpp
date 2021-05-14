#include<iostream> 
#include<string>
using namespace std;

int lastOcer(char *c , char f){
     if(*c =='\0')
        return -1;
    lastOcer(c+1 , f);
    static int i = 0 ;
    if(*c == f )
        return i ;
    
    i++;
}


// code 2
// int find(char *str, char c, int n)
// {
// 	if(n==0)
// 		return -1;
// 	if(str[n-1]==c)
// 		return n-1;
// 	return find(str,c,n-1);
// }

int main(int argc, char const *argv[])
{
    string s ; cin >> s ;

    char c ; cin >> c ;

    cout << lastOcer(&s[0],c);
    return 0;
}