#include<iostream>
using namespace std;

int partation(int *A,int start,int end);

int swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

void quickSort(int *A ,int start , int end)
{
    if(start>=end)
    return;
    else
    {
        int pIndex = partation(A,start,end);
        quickSort(A,start,pIndex-1);
        quickSort(A,pIndex+1,end);
    }
};

int partation(int *A,int start ,int end)
{
    int pivot = A[end];
    int pIndex_2 = start;
    for(int i = start ; i <= end-1;i++) 
    {
        if(A[i]<pivot)
        {
            swap(&A[i],&A[pIndex_2]);
            pIndex_2++;
        }
    }
    swap(&A[pIndex_2],&A[end]);
    return pIndex_2 ;
};

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int A[n],j,temp;

    for(int i = 0 ; i<n ; i++)
    {
        cout<<"----------"<<i<<"------------"<<endl;
        cin>>A[i];
    }


    quickSort(A,0,n-1);

    // print elements
    for(int i = 0 ; i < n ;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;

}    