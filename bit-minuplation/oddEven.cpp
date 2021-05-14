// C++ program to check for even or odd
// using Bitwise XOR operator
 
#include <iostream>
using namespace std;
 
// Returns true if n is even, else odd
bool isEven(int n)
{
    // if((n | 1) >  n) return true;
    // if((n ^  1) > n) return true;
    if((n & 1) == 0) return true;
    else 
        return false;
}
 
// Driver code
int main()
{
    int n ; cin >> n;
    isEven(n)
? cout << "even"
: cout << "odd";
 
    return 0;
}