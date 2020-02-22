#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n],j,temp;

    for(int i = 0 ; i<n ; i++)
    {
        cout<<"----------"<<i<<"------------"<<endl;
        cin>>A[i];
    }

    for(int i = 1 ; i<n ;i++)
    {
        j = i;
        while(j>0 and A[j] < A[j-1])
        {
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
            j--;
        }
    }

    for(int i = 0 ; i < n ;i++)
    {
        cout<<A[i]<<"\t";
    }
}
