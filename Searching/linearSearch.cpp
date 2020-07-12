#include <iostream>
#include <array>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int *a = new int(n);
    int found;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to find :" ;
    cin >> found;
    for (auto i = 0; i < n; i++)
    {
        if(found == a[i])
            cout << "\nelement found at index :" << i;
        
    }
    cout << endl;
    
     
    return 0;
}
