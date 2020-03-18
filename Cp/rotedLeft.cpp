#include<iostream>
using namespace std;

int main()
{
    int n,d;cin>>n>>d;
    int a[n],temp;

    for(int i = 0 ; i<n ; i++)
      cin>>a[i];

        for(int i = 0 ; i<=d-1 ;i++)
    {
        int j = 0;
        temp = a[j];
        while(j < n)
        {
        a[j] = a[j+1];
        j++;
        }
        a[n-1] = temp;
    }

    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
    return 0;
}