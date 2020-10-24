#include <iostream>
using namespace std;

int leftChildNode(int i){ return 2*i +1;}
int rightChildNode(int i){ return 2*i+2;}

void heapeify(int a[], int n, int i){
    int l = leftChildNode(i);
    int r = rightChildNode(i);
    int largest = i;
    if(l < n and a[l] > a[largest])
        largest = l;
    if(r < n and a[r] > a[largest])
        largest = r;
    if(largest != i){
        swap(a[i],a[largest]);
        heapeify(a,n,largest);
    }

}

void heapSort(int a[] , int n) {

    // build maxheap
    for(int i = n/2-1 ; i>=0 ; i--)
        heapeify(a,n,i);
    
    // delete maxheap
    for (int i = n-1; i>0; i--)
    {
        swap(a[0],a[i]);
        heapeify(a , i, 0);
    }
    
}
void display(int a[], int n)
{
    cout << "heap elements are " << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}



int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int a[n];
    for(int i=0 ; i < n ; i++)
        cin >> a[i];

    heapSort(a,n);
    display(a,n);
    
    
    return 0;
}
