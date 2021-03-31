#include <iostream>
using namespace std;

int partation(int *a , int top , int end){
    int pivet = a[top];
    int s = top;
    int e = end;
    while(top < end){
        while(a[s] <= pivet)
            s++;
        while(a[e] > pivet)
            e--;
        if(s < e){
            swap(a[s],a[e]);
        }
    }
    swap(a[e],a[top]);
    return e;

}

void quickSort(int *a , int top , int end){
    if(top < end){
        int p = partation(a,top,end);
        quickSort(a,top,p+1);
        quickSort(a,p+1,end);

    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);

    // print elements
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    return 0;
}
