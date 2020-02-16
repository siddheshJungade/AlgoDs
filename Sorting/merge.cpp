#include <iostream>
using namespace std;

int merge(int A[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = A[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = A[m + i + 1];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            A[k] = arr1[i];
            i++;
        }
        else
        {
            A[k] = arr2[j];
            j++;
        }
        k++;
    }

   while (i < n1) 
    { 
        A[k] = arr1[i]; 
        i++; 
        k++; 
    }

    while (i < n1) 
    { 
        A[k] = arr2[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}
main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
    {
        cout << "----------" << i << "------------" << endl;
        cin >> A[i];
    }
    mergeSort(A,0, n - 1);
    for (int i = 0; i < n; i++)
    {
        
        cout <<"\t"<< A[i] <<"\t";
    }
}
