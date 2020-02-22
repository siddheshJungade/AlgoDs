#include<iostream>
using namespace std;

main()
{
   
    int n;
    cin>>n;
    int A[n],j,temp;

    for(int i = 0 ; i<n ; i++)
    {
        cout<<"----------"<<i<<"------------"<<endl;
        cin>>A[i];
    } 

    // Selection Sort
    
    for ( int i = 0; i < n ; i++)
    {
      int minIndex = i;
      for(int j = i+1 ; j <= n-1 ; j++)
      {
          if(A[j]<A[j-1])
          {
              minIndex = j;
          }
      }
      swap(A[i],A[minIndex]);  
    }
    

    // print elements
    for(int i = 0 ; i < n ;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
}