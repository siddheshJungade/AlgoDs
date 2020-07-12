#include <iostream>

int fun (int n)
{
    if(n > 100)
        return n-10;
    return fun(fun(n+11));
}

int main(int argc, char const *argv[])
{
    int r;
    r = fun(22);
    printf("%d",r);
    return 0;
}
